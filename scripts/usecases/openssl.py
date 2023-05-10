import usecases.case as case
import subprocess
import os
import asyncio

class OpenSSL(case.LLVMCompilableUseCase):

    def __init__(self, function_name, original_file_location, variant_text_location, line_start, line_end, name="openssl"):
        super().__init__()
        self.name = name
        self.function_name = function_name
        self.variant_text_location = variant_text_location
        self.original_file_location = original_file_location
        self.change_location=(original_file_location, line_start, line_end)

        self.test_result = None

    def replace(self, cwd):
        (source, start, end) = self.change_location
        # This path is in the shadow folder of the new compilation
        source = os.path.join(cwd, source)
        original_source = os.path.join(self.original_file_location)

        variant_function = open(self.variant_text_location, "r").readlines()
        
        original_content = open(original_source, "r").readlines()
        variant = original_content[:start] + variant_function + original_content[end:]
        variant = "\n".join(variant)

        print("Changing source code at", source, ".Compiling...")

        f = open(source, "w")
        f.write(variant)
        f.close()


    async def run_tests(self, cwd):
        if not self.tested:
            try:
                self.replace()
                ch = subprocess.check_output(["./Configure"], env={**os.environ, "CFLAGS": "-save-temps", "CC": "clang", "CXX": "clang++", "CXXFLAGS": "-save-temps"}, shell=True, cwd=cwd, stderr=subprocess.DEVNULL)
                ch = subprocess.check_output(["make", "test", "-j", "24"], cwd=cwd, stderr=subprocess.DEVNULL)
                self.tested = True
                self.test_result = True
                return True
            except Exception as e:
                print(e)
                self.test_result = True
                return False
            
        return self.test_result

    async def compile(self, cwd):

        if not self.compiled:
            self.replace(cwd)
            # Lets set ccache to speed up
            ch = subprocess.check_output(["./Configure"], env={**os.environ, "CFLAGS": "-save-temps", "CC": "clang", "CXX": "clang++", "CXXFLAGS": "-save-temps"}, shell=True, cwd=cwd, stderr=subprocess.DEVNULL)
            ch = subprocess.check_output(["make", "-j", "24"], cwd=cwd, stderr=subprocess.DEVNULL)
            self.compiled = True
        # block here?

