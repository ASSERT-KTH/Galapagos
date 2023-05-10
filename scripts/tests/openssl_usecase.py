
import asyncio
import usecases.openssl
from usecases.case import is_executable
import verifier
import logging
import json
import os
import traceback



if __name__ == "__main__":
    # Compile openssl
    logging.basicConfig(level=logging.DEBUG)
    
    verif = verifier.AliveVerifier(debug=True)

    async def compare(original_folder, shadow1, original: usecases.openssl.OpenSSL, variant: usecases.openssl.OpenSSL):
        # The first one does not need to compile

        variant_shadow = await variant.shadow(original_folder)

        result = {
            "compiled": False
        }

        try:

            await variant.compile(variant_shadow)
            result['compiled'] = True

            # TODO check for changes, bitcodes,  binaries and source code
            modified, in1, in2 = await variant.compare_shadows(shadow1, variant_shadow)
            result['changes'] = {}
            result['all'] = modified
            result['only_in_original'] = in1
            result['only_in_destiny'] = in2

            # There should not be new or removed files
            assert len(in1) == 0, "The new compilation removes files. That is not possible"
            assert len(in2) == 0,  "The new compilation adds new files. That is not possible"
            logging.info(f"Modified files {len(modified)}")
            
            bitcodes = [ (f1, f2) for f1, f2 in modified if f1.endswith(".bc") and f2.endswith(".bc") ]
            executables = [ (f1, f2) for f1, f2 in modified if is_executable(f1) and is_executable(f2) ]
            source_code = [(f1, f2) for f1, f2 in modified if (f1.endswith(".c") or f1.endswith(".cpp")) and (f2.endswith(".c") or f2.endswith(".cpp"))]

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
                        tasks.append((f1, f2, asyncio.create_task(verif.async_verify(open(f1, 'r'), open(f2, 'r'), entrypoint="bn_free_d", timeout=300_000))))

                    pass_test = await pass_test
                    result['pass_tests'] = pass_test

                    result['verification'] = {}
                    if pass_test:
                        # Then wait for the verification tasks
                        for f1, f2, t in tasks:
                            result[os.path.basename(f1)] = await t
                    else:
                        logging.warning("The tests did not pass, so we will not verify the bitcodes")
                        for f1, f2, t in tasks:
                            # cancel the task
                            # 0 timeout means that it will be cancelled immediately
                            asyncio.wait_for(t, 0.0)


        except Exception as e:
            logging.warning(f"Could not compile variant {variant.name} {e}")
            result['python_error_trace'] = traceback.format_exc()
            result['python_error_msg'] = f"{e}"
            return
        finally:
            # Save the file as a json
            function_folder = f"out/openssl/{variant.function_name}"
            os.makedirs(function_folder, exist_ok=True)
            with open(f"{function_folder}/{variant.name}.result.json", 'w') as f:
                json.dump(result, f, indent=4)
        
        return result
    
    async def main():

        # We compile the original first
        openssl_project_folder = "../../use_cases/openssl"
        original_uc = usecases.openssl.OpenSSL("all", None, None, None, 0, 0, "openssl", doreplace = False)

        # UNcomment this for real
        # original_uc.compiled = True
        # original_uc.tested = True

        shadow_original = await original_uc.shadow(openssl_project_folder, name="opensslt1")
        await original_uc.compile(shadow_original)

        # Reading the functions and the variants
        # Reading json inside ../../functions/openssl/functions_info.json
        test_cases = []
        with open("../../functions/openssl/functions_info.json", 'r') as f:
            functions_info = json.load(f)
            for function in functions_info:
                logging.info(f"Pipeline for variants of {function['name']} {function['path']}")

                # Reading the generated variants 
                for variant_of_function in os.listdir("../../functions/openssl/variants"):
                    if variant_of_function == function['name']:
                        # Then this is the variants for that function
                        for variant_file in os.listdir(f"../../functions/openssl/variants/{variant_of_function}"):
                            testcase = usecases.openssl.OpenSSL(
                                variant_of_function,
                                original_project_folder=openssl_project_folder, 
                                original_file_location=f"{function['path']}",
                                variant_text_location=os.path.abspath(f"../../functions/openssl/variants/{variant_of_function}/{variant_file}"),
                                line_start=function['line'],
                                line_end=function['end'],
                                name=os.path.basename(variant_file),
                                doreplace=True
                            )
                            test_cases.append(testcase)
                            

        # Comment this out
        test_cases = test_cases[:1]
        print(len(test_cases))

        tasks = []
        for test in test_cases:
            tasks.append(asyncio.create_task(compare("../../use_cases/openssl",shadow_original, original_uc, test)))

        results = await asyncio.gather(*tasks)
        print(results)








    asyncio.run(main())


