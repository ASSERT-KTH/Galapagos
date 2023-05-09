import usecases.case as case
import subprocess
import os
import asyncio

class OpenSSL(case.LLVMCompilableUseCase):

    def __init__(self):
        super().__init__()

        self.initial_source_code = open(os.path.join(os.path.dirname(__file__), "bn_lib.c"), "r").read()
        self.changed_source_code = open(os.path.join(os.path.dirname(__file__), "bn_lib.2.c"), "r").read()
        self.change_location=("crypto/bn/bn_lib.c", 0, -1)
        
    async def run_tests(self, cwd):
        pass

    async def compile(self, cwd, source_code):

        if not self.compiled:
            (source, head, tail) = self.change_location
            source =os.path.join(cwd, source)
            print("Changing source code at", source, ".Compiling...")

            f = open(source, "w")
            f.write(source_code)
            f.close()

            # Lets set ccache to speed up
            ch = subprocess.check_output(["./Configure"], env={**os.environ, "CFLAGS": "-save-temps", "CC": "clang", "CXX": "clang++", "CXXFLAGS": "-save-temps"}, shell=True, cwd=cwd, stderr=subprocess.DEVNULL)
            ch = subprocess.check_output(["make", "-j", "24"], cwd=cwd, stderr=subprocess.DEVNULL)
            self.compiled = True
        # block here?

