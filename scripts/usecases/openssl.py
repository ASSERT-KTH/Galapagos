import usecases.case as case
import subprocess
import os
import asyncio
import logging
import traceback
import time
import re

class OpenSSL(case.LLVMCompilableUseCase):

    def __init__(self, function_name, original_project_folder, original_file_location, variant_text_location, line_start, line_end, name="openssl", doreplace=True):
        super().__init__()
        self.name = name
        self.function_name = function_name
        self.original_project_folder = original_project_folder
        self.variant_text_location = variant_text_location
        self.original_file_location = original_file_location
        self.change_location=(original_file_location, line_start, line_end)

        self.test_result = None
        self.doreplace = doreplace

    def replace(self, cwd):
        if self.doreplace:
            (source, start, end) = self.change_location
            # This path is in the shadow folder of the new compilation
            source = os.path.join(cwd, source)
            original_source = os.path.join(self.original_project_folder, self.original_file_location)

            variant_function = open(self.variant_text_location, "r").readlines()


            original_content = open(original_source, "r").readlines()
            # TODO wrap function into our own comments to help in finding (manually) for bugs
            variant = original_content[:start-1] + variant_function + ["\n"] + original_content[end + 1:]
            variant = "".join(variant)

            open(f"{self.name}.all.c", "w").write(variant)


            # print(variant)
            logging.info(f"Changing source code at {source}.")

            f = open(source, "w")
            f.write(variant)
            f.close()
        else:
            logging.info("No change provided")


    async def run_tests(self, cwd):
        start = time.time()
        logging.info("Testing")
        if not self.tested:
            try:
                # We do not need to replace again
                # self.replace(cwd)
                # ch = subprocess.check_output(["./Configure"], env={**os.environ, "CFLAGS": "-save-temps", "CC": "clang", "CXX": "clang++", "CXXFLAGS": "-save-temps"}, shell=True, cwd=cwd, stderr=subprocess.STDOUT)
                ch = subprocess.run(["make", "test", "-j", "24"], cwd=cwd, check=False, capture_output=True, text=True)
                self.tested = True
                self.test_result = ch.returncode == 0, ch.stdout.decode()
                print(f"Tested in {time.time() - start:.2f}s")
                return ch.returncode == 0, ch.stdout, ch.stderr
            except Exception as e:
                print(e)
                self.test_result = False, f"{e}\n{traceback.format_exc()}"
                return False, f"{e}"

        return self.test_result

    async def compile(self, cwd):
        logging.info("Compiling")
        start = time.time()
        if not self.compiled:
            self.replace(cwd)
            # Lets set ccache to speed up
            ch = subprocess.check_output(["./Configure"], env={**os.environ, "CFLAGS": "-save-temps", "CC": "clang", "CXX": "clang++", "CXXFLAGS": "-save-temps"}, shell=True, cwd=cwd, stderr=subprocess.STDOUT)
            ch = subprocess.run(["make", "-j", "24"], cwd=cwd, check=False, capture_output=True,text=True)
            print(f"Compiled in {time.time() - start:.2f}s")
            if ch.returncode != 0:
                return False, ch.stdout, ch.stderr
            else:
                return True, ch.stdout, ch.stderr

            self.compiled = True
        # block here?

