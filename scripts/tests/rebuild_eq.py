
import asyncio
from usecases.case import is_executable, CLONE_PATH
import verifier
import logging
import json
import os
import traceback
import sys
import shutil

DIRNAME = os.path.abspath(os.path.dirname(__file__))
CLONE_PATH = '/mnt/ssd2/diogo/galapagos-clones'

# TODO: remove these comments, only here for reference (as typing is not working)
# original is the original use case, is of type usecases.<LIBRARY>.<LIBRARY>
# variant is the variant use case, is of type usecases.<LIBRARY>.<LIBRARY>
async def compare(original_folder, shadow1, original, variant, n, library, lang):
    # The first one does not need to compile
    variant_shadow = await variant.shadow(original_folder)

    result = {
        "compiled": False,
        "function_name": variant.function_name,
        "variant_name": variant.name,
        # For other libraries, replace this name
        "project": library
    }
    # Make partial saving of the results
    def save(ot):
        function_folder = f"out/{library}/{lang}/{variant.function_name}"
        os.makedirs(function_folder, exist_ok=True)
        with open(f"{function_folder}/{variant.function_name}_{n}.result.json", 'w') as f:
            json.dump(result, f, indent=4)


    try:
        # TODO: do I really need to compile everything? shouldn't compile in isolation suffice?
        await variant.compile(variant_shadow) # raises exception on fail
        result['compiled'] = True 

        # TODO check for changes, bitcodes, binaries and source code
        print(f"Comparing shadows {shadow1} {variant_shadow}")
        modified, in1, in2 = await variant.compare_shadows(shadow1, variant_shadow)
        # print(f"Modified {modified} in1 {in1} in2 {in2}")
        result['changes'] = {}

        # There should not be new or removed files
        # assert len(in1) == 0, "The new compilation removes files. That is not possible"
        # assert len(in2) == 0,  "The new compilation adds new files. That is not possible"
        logging.info(f"Modified files {len(modified)}")

        # The following filters depends on each project
        bitcodes = [ (f1, f2) for f1, f2 in modified if f1.endswith(".bc") and f2.endswith(".bc") ]
        logging.info(f"Bitcodes {len(bitcodes)}")
        result['changes']['bitcodes'] = bitcodes


    except Exception as e:
        logging.warning(f"Could not compile variant {variant.name} {e}")
        result['python_error_trace'] = traceback.format_exc()
        result['python_error_msg'] = f"{e}"
        # result['variant_text'] = variant.variant_text
        return
    finally:
        # Save the file as a json
        save(result)
    return result

async def main():
    logging.basicConfig(level=logging.DEBUG)

    eq_variants = {}
    with open("eq_variants.json", 'r') as f:
        eq_variants = json.load(f)

    # for library

    # Reading the functions and the variants
    tasks = []
    test_cases = []
    for library in eq_variants:
        project_folder = f"../../use_cases/{library}"
        project_folder = os.path.join(DIRNAME, project_folder)
        
        uc_name = f"usecases.case"
        uc_name = __import__(uc_name).case
        original_uc = uc_name.LibraryCompilableUseCase("all", None, None, None, 0, 0, library, doreplace = False)

        shadow_original = f"{CLONE_PATH}/{library}"

        WORKSPACE = os.path.join(DIRNAME, f"../../functions/{library}")
        functions_info = {}
        with open(os.path.join(WORKSPACE, "functions_info.json"), 'r') as f:
            functions_info = json.load(f)

        for function in functions_info:
            # Reading the generated variants
            for lang in ['c', 'go']:
                langfiles = [f for f in os.listdir(f"{WORKSPACE}/variants/{lang}") if f.endswith(f'.{lang}')]
                for variant_of_function in langfiles:
                    chunks = variant_of_function.replace(f'.{lang}', '').split("_")
                    funcname = '_'.join(chunks[:-1]) #hack
                    if function['name'] not in funcname or function['name'] not in eq_variants[library]:
                        continue
                    func_version = chunks[-1] # hack
                    
                    if func_version not in eq_variants[library][function['name']][lang]:
                        continue

                    testcase = uc_name.LibraryCompilableUseCase(
                            funcname,
                            original_project_folder=project_folder,
                            original_file_location=f"{function['bc_file_path']}",
                            variant_text_location=os.path.abspath(f"{WORKSPACE}/variants/{lang}/{variant_of_function.replace(f'.{lang}', '.bc')}"),
                            name=library,
                            doreplace=True,
                            real_name=function['name'],
                            version=func_version,
                            lang=lang,
                            name_bc_go=function['fn_bc_name_go']
                    )
                    print(f'rebuilding {library} {function["name"]} {func_version} {lang}')
                    test_cases.append((testcase, library, lang))

    for i, (test, library, lang) in enumerate(test_cases):
        tasks.append(asyncio.create_task(compare(os.path.join(DIRNAME, f"{CLONE_PATH}/{library}"), shadow_original, original_uc, test, i, library, lang)))
    await asyncio.gather(*tasks)



if __name__ == "__main__":
    asyncio.run(main())
