
import usecases.case as case
import subprocess
import os
import asyncio
import logging
import traceback
import time

class libsodium(case.LLVMCompilableUseCase):

    def __init__(self, function_name, original_project_folder, original_file_location, variant_text_location, line_start, line_end, name="libsodium", doreplace=True):
        super().__init__()
        logging.warning("Make sure libtool is installed in your system, otherwise the compilation of libsodium wont work")
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

            open("tmp.c", "w").write(variant)
            self.variant_text = variant_function


            # print(variant)
            logging.info(f"Changing source code at {source} {start}:{end}.")

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
                self.replace(cwd)
                # ch = subprocess.check_output(["./Configure"], env={**os.environ, "CFLAGS": "-save-temps", "CC": "clang", "CXX": "clang++", "CXXFLAGS": "-save-temps"}, shell=True, cwd=cwd, stderr=subprocess.STDOUT)
                ch = subprocess.check_output(["make", "test", "-j", "16"], cwd=cwd, stderr=subprocess.STDOUT)
                self.tested = True
                self.test_result = True, ch.decode()
                print(f"Tested in {time.time() - start:.2f}s")
                return True, ch.decode()
            except Exception as e:
                print(e)
                self.test_result = False, f"{e}\n{traceback.format_exc()}"
                return False, f"{e}"

        return self.test_result

    async def compile(self, cwd):
        logging.info(f"Compiling {cwd}")
        start = time.time()
        if not self.compiled:
            self.replace(cwd)
            # Lets set ccache to speed up
            logging.info("Setting up autogen")
            ch = subprocess.check_output(["./autogen.sh", "-s"], env={**os.environ, "CFLAGS": "-save-temps", "CC": "clang", "CXX": "clang++", "CXXFLAGS": "-save-temps"},
                shell=True,
                cwd=cwd,
                stderr=subprocess.STDOUT)
            logging.debug(ch.decode())
            logging.info("Calling configure")
            ch = subprocess.check_output(["./configure"], env={**os.environ, "CFLAGS": "-save-temps", "CC": "clang", "CXX": "clang++", "CXXFLAGS": "-save-temps"},
                shell=True,
                cwd=cwd,
                stderr=subprocess.STDOUT)

            logging.info("Calling make")
            try:
                ch = subprocess.check_output(["make", "-j", "16"], cwd=cwd, stderr=subprocess.STDOUT)
                print(f"Compiled in {time.time() - start:.2f}s")
                self.compiled = True
            except Exception as e:
                print(e)
                self.compiled = False
                raise e
        # block here?

