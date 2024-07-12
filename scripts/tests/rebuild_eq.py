
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
CLONE_PATH = '/home/javier/galapagos-clones'

async def main():
    logging.basicConfig(level=logging.DEBUG)

    eq_variants = {}
    with open("eq_variants.json", 'r') as f:
        eq_variants = json.load(f)

    # for library

    # Reading the functions and the variants
    for library in eq_variants:
        project_folder = f"../../use_cases/{library}"
        project_folder = os.path.join(DIRNAME, project_folder)
        
        uc_name = f"usecases.case"
        uc_name = __import__(uc_name).case

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
                    shadow = await testcase.shadow(os.path.join(DIRNAME, f"{CLONE_PATH}/{library}"))
                    await testcase.compile(shadow)



if __name__ == "__main__":
    asyncio.run(main())
