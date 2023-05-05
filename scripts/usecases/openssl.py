import case
import subprocess
import os
import asyncio

class OpenSSL(case.LLVMCompilableUseCase):

    def __init__(self, opensslfolder):
        super().__init__()
        self.opensslfolder = opensslfolder

        self.initial_source_code = open(os.path.join(os.path.dirname(__file__), "e_dec.test.c"), "r").read()
        self.changed_source_code = open(os.path.join(os.path.dirname(__file__), "e_dec.test2.c"), "r").read()
        self.source_code = self.initial_source_code
        self.change_location=("../../use_cases/openssl/crypto/evp/e_des.c", 0, -1)


    def compile(self):
        ch = subprocess.check_output(["./Configure"], cwd=self.opensslfolder, env={**os.environ, "CFLAGS": "-save-temps", "CC": "clang", "CXX": "clang++", "CXXFLAGS": "-save-temps"}, shell=True)
        ch = subprocess.check_output(["make"], cwd=self.opensslfolder)

    '''
        Change the source code of openssl by source_file[:head] + replacement + source_file[tail:]
    '''
    def change_code_in(self, source_file, headposition, tailposition, replacement):
        # Save the original again
        original = open(source_file, "r").read()
        # Change the source code
        f = open(source_file, "w")
        f.write(original[:headposition] + replacement + original[tailposition:] if tailposition != -1 else "")
        f.close()

    def test_change(self):
        self.source_code = self.changed_source_code
        (source, head, tail) = self.change_location
        self.change_code_in(source, head, tail, self.source_code)

    '''
        Either call git reset or call the change_code_in with the original piece of code
    '''
    def reset(self):
        self.source_code = self.initial_source_code


if __name__ == "__main__":
    # Compile openssl
    import sys
    uc = OpenSSL(sys.argv[1])

    async def mm():
        t = asyncio.create_task(uc.create_watchdog(sys.argv[1]))
        await asyncio.sleep(2)
        # print(changed_source_codes)
        # print([(c,uc.state[c]) for c in changed_source_codes if c.endswith(".cpp") or c.endswith(".bc") or c.endswith(".o")])
        # Ideally this can be done in parallel
        # TODO copy the folder to another location and trigger the compilation there
        uc.compile()
        # change the source code
        changed_source_codes = uc.get_last_changed()
        uc.test_change()
        # TODO copy the folder to another location  and trigger the compilation there
        uc.compile()
        changed_compilable = uc.get_last_changed()

        print([(c, uc.state[c]) for c in changed_compilable if not c.endswith(".i") and not c.endswith(".s") and not c.endswith(".ll")])
        # changed_cource_code -> changed_compilable


    asyncio.run(mm())

    # change source code
    # compile again
    # verify changed Bitcodes

