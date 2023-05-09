import case
import subprocess
import os
import asyncio

class OpenSSL(case.LLVMCompilableUseCase):

    def __init__(self):
        super().__init__()

        self.initial_source_code = open(os.path.join(os.path.dirname(__file__), "bn_lib.c"), "r").read()
        self.changed_source_code = open(os.path.join(os.path.dirname(__file__), "bn_lib.2.c"), "r").read()
        self.change_location=("crypto/bn/bn_lib.c", 0, -1)


    async def compile(self, cwd, source_code):

        (source, head, tail) = self.change_location
        source =os.path.join(cwd, source)
        print("Changing source code at", source, ".Compiling...")

        f = open(source, "w")
        f.write(source_code)
        f.close()

        # Lets set ccache to speed up
        ch = subprocess.check_output(["./Configure"], env={**os.environ, "CFLAGS": "-save-temps", "CC": "clang", "CXX": "clang++", "CXXFLAGS": "-save-temps"}, shell=True, cwd=cwd, stderr=subprocess.DEVNULL)
        ch = subprocess.check_output(["make", "-j", "16"], cwd=cwd, stderr=subprocess.DEVNULL)

        # block here?




if __name__ == "__main__":
    # Compile openssl
    import sys
    uc = OpenSSL()

    async def comp1(src):
        shadow = await uc.shadow(src, name="opensslt1")
        await uc.compile(shadow, uc.initial_source_code)

        return shadow

    async def comp2(src):
        shadow = await uc.shadow(src, name="opensslt2")
        await uc.compile(shadow, uc.changed_source_code)
        return shadow


    async def mm():
        shadow1 = asyncio.create_task(comp2(sys.argv[1]))
        shadow2 = asyncio.create_task(comp1(sys.argv[1]))

        shadow1 = await shadow1
        shadow2 = await shadow2

        # TODO we can call this function as "clone" instead of shadow
        print("Comparing files")
        modified = await uc.compare_shadows(shadow1, shadow2)
        # changed_cource_code -> changed_compilable
        print(modified)


    asyncio.run(mm())

    # change source code
    # compile again
    # verify changed Bitcodes
