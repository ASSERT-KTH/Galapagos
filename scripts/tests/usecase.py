
import asyncio
import usecases.case
import verifier
import logging
import json
import os
import traceback
import sys
import shutil


DIRNAME = os.path.abspath(os.path.dirname(__file__))
LIBRARY = sys.argv[1] # TODO: check if this is correct, check if str() is needed

if __name__ == "__main__":
    # Compile library
    print(f"Results will be in {os.path.abspath(f'out/{LIBRARY}')}")
    logging.basicConfig(level=logging.DEBUG)

    verif = verifier.AliveVerifier(debug=True)

    # TODO: remove these comments, only here for reference (as typing is not working)
    # original is the original use case, is of type usecases.<LIBRARY>.<LIBRARY>
    # variant is the variant use case, is of type usecases.<LIBRARY>.<LIBRARY>
    async def compare(original_folder, shadow1, original, variant):
        # The first one does not need to compile

        # Fix name for faster compile. In theory the name is unique ?
        # variant_shadow = await variant.shadow(original_folder, name=f"{variant.name.replace('.', '_')}")
        variant_shadow = await variant.shadow(original_folder)

        result = {
            "compiled": False,
            "function_name": variant.function_name,
            "variant_name": variant.name,
            # For other libraries, replace this name
            "project": LIBRARY
        }

        # Make partial saving of the results
        def save(ot):
            function_folder = f"out/{LIBRARY}/{variant.function_name}"
            os.makedirs(function_folder, exist_ok=True)
            with open(f"{function_folder}/{variant.name}.result.json", 'w') as f:
                json.dump(result, f, indent=4)


        try:

            await variant.compile(variant_shadow) # raises exception on fail
            result['compiled'] = True 

            # TODO check for changes, bitcodes, binaries and source code
            modified, in1, in2 = await variant.compare_shadows(shadow1, variant_shadow)
            result['changes'] = {}
            result['all'] = modified
            result['only_in_original'] = in1
            result['only_in_destiny'] = in2

            # There should not be new or removed files
            assert len(in1) == 0, "The new compilation removes files. That is not possible"
            assert len(in2) == 0,  "The new compilation adds new files. That is not possible"
            logging.info(f"Modified files {len(modified)}")

            # The following filters depends on each project
            bitcodes = [ (f1, f2) for f1, f2 in modified if f1.endswith(".bc") and f2.endswith(".bc") ]

            executables = [ (f1, f2) for f1, f2 in modified if is_executable(f1) and is_executable(f2) ]
            executables = [(f1, f2) for f1, f2 in executables if "test" not in f1 and "test" not in f2]

            source_code = [(f1, f2) for f1, f2 in modified if (f1.endswith(".c") or f1.endswith(".cpp") or f1.endswith(".h")) and (f2.endswith(".c") or f2.endswith(".cpp") or f2.endswith(".h"))]

            assert len(source_code) > 0, "There are not changed source codes"


            logging.info(f"Bitcodes {len(bitcodes)}")
            logging.info(f"Executables {len(executables)}")


            result['changes']['source_code'] = source_code
            result['changes']['bitcodes'] = bitcodes
            result['changes']['executables'] = executables
            result['shadow_folder'] = variant_shadow

            if len(bitcodes) == 0:
                logging.warning("Warning there are not changed bitcodes. Either you are not changing the source code or the transormation is not preserved")
                result['preserved_in_bc'] = False
            else:
                result['preserved_in_bc'] = True
                # Check if there is at least one changed binary, otherwise the transformation is not preserved
                if len(executables) == 0:
                    result['preserved_in_ex'] = False
                    logging.warning("No binary changed, meaning that probably no transformation is preserved")
                else:
                    result['preserved_in_ex'] = True
                    # Do the verification of the bitcodes
                    logging.info("Doing tests")
                    pass_test = asyncio.create_task(variant.run_tests(variant_shadow))
                    tasks = []
                    for f1, f2 in bitcodes:
                        logging.info(f"Verifying {f1} {f2}")
                        tasks.append((f1, f2, asyncio.create_task(verif.async_verify(open(f1, 'r'), open(f2, 'r'), entrypoint=variant.real_name, timeout=300_000))))

                    pass_test, msg = await pass_test
                    result['pass_tests'] = pass_test
                    result['test_result'] = msg

                    result['verification'] = {}
                    if pass_test:
                        # Then wait for the verification tasks
                        for f1, f2, t in tasks:
                            result[os.path.basename(f1)] = (await t).toJSON()
                    else:
                        logging.warning("The tests did not pass, so we will not verify the bitcodes")
                        for f1, f2, t in tasks:
                            # cancel the task
                            # 0 timeout means that it will be cancelled immediately
                            t.cancel()


        except Exception as e:
            logging.warning(f"Could not compile variant {variant.name} {e} \n{variant.variant_text}")
            result['python_error_trace'] = traceback.format_exc()
            result['python_error_msg'] = f"{e}"
            result['variant_text'] = variant.variant_text
            return
        finally:
            # Save the file as a json
            save(result)
        return result

    async def main():

        # We compile the original first
        project_folder = f"../../use_cases/{LIBRARY}"

        project_folder = os.path.join(DIRNAME, project_folder)

        uc_name = f"usecases.case"
        uc_name = __import__(uc_name).case
        original_uc = uc_name.LibraryCompilableUseCase("all", None, None, None, 0, 0, LIBRARY, doreplace = False)

        # UNcomment this for real
        # original_uc.compiled = True
        # original_uc.tested = True

        shadow_original = await original_uc.shadow(project_folder, name=f"{LIBRARY}")
        await original_uc.compile(shadow_original)

        # Reading the functions and the variants
        # Reading json inside ../../functions/openssl/functions_info.json
        test_cases = []
        WORKSPACE = os.path.join(DIRNAME, f"../../functions/{LIBRARY}")
        with open(os.path.join(WORKSPACE, "functions_info.json"), 'r') as f:
            functions_info = json.load(f)
            for idx, function in enumerate(functions_info):
                logging.info(f"Pipeline for variants of {function['name']} {function['path']}")

                # Reading the generated variants
                for variant_of_function in os.listdir(f"{WORKSPACE}/variants"):
                    chunks = variant_of_function.split(".")
                    funcname, extension, prompt = chunks[:3]
                    #idx = funcname.split("_")[0]
                    #funcname = funcname[len(idx)+1:]

                    if funcname == f"{idx}_{function['name']}":
                        print(variant_of_function)
                        # Then this is the variants for that function
                        #for variant_file in os.listdir(f"{WORKSPACE}/variants/{variant_of_function}"):
                        # TODO: still must check if this call works
                        testcase = uc_name.LibraryCompilableUseCase(
                                funcname,
                                original_project_folder=project_folder,
                                original_file_location=f"{function['path']}",
                                variant_text_location=os.path.abspath(f"{WORKSPACE}/variants/{variant_of_function}"),
                                line_start=function['line'],
                                line_end=function['end'],
                                name=LIBRARY,
                                doreplace=True,
                                real_name=function['name']
                        )
                        test_cases.append(testcase)



        # Comment this out
        test_cases = test_cases[:1]
        logging.info(f"Variants to check {len(test_cases)}")
        assert len(test_cases) > 0, "There are no variants to check"
        # assert len(test_cases) == 2000, "THere should be 2000 verifications"

        tasks = []
        for test in test_cases:
            tasks.append(asyncio.create_task(compare(os.path.join(DIRNAME, f"../../use_cases/{LIBRARY}"),shadow_original, original_uc, test)))
            # break

        results = await asyncio.gather(*tasks)


    asyncio.run(main())


