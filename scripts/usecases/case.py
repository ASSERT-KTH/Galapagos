import watchdog
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
import asyncio

import hashlib
import shutil
import subprocess
import logging
import os
import shutil
import  uuid

'''
    Returns true f the a file is executable. Useful for compiled binaries
'''
def is_executable(f):
    return os.access(f, os.X_OK)



'''
    Saves the file in the debug folder and returns the hash of the file
'''
def hash_of_file(file):
    # TODO copy the file
    try:
        with open(file, "rb") as f:
            file_hash = hashlib.md5()
            while chunk := f.read(8192):
                file_hash.update(chunk)
        return file_hash.hexdigest()
    except Exception as e:
        # logging.error(e)
        return None
'''
    Define a use case to compile a library or a binary, detect LLVM bitcodes changed during compilation, and replace C/C++ code in the basecode.
'''
class UseCase(FileSystemEventHandler):

    def __init__(self, debug=False):
        self.observer = None
        # The state is a map of the filepath vs hash of the file in time
        # A file changes if the last hash is != of the current hash
        # TODO move this to REDIS ?
        logging.info("Creating the empty state")
        self.state = {  }
        self.debug = debug



    '''
        Creates a github repo on the temp folder if it does not exist. Then create a random branch to modify the things. Add all new files bc, i, s force it. Returns the temp folder and the name of the temp branch
    '''
    async def shadow(self, src, name=None):
        print(f"Shadowing {src}")
        # Create a folder in tmp
        # Copy the src folder to the tmp folder
        # Return the tmp folder
        # use a random name

        random_name = "envy-%s"%str(uuid.uuid4()) if not name else name
        print(f"Copying {src} to /tmp/{random_name}")
        tmp_folder = os.path.join("/tmp", random_name)
        # if the folder exist, prevent the copy
        if os.path.exists(tmp_folder):
            return tmp_folder

        shutil.copytree(src, tmp_folder, symlinks=False, ignore=None, copy_function=shutil.copy, ignore_dangling_symlinks=False)
        os.sync()
        return tmp_folder

    async def compare_shadows(self, src, dst):
        # traverse root directory, and list directories as dirs and files as files
        modified = []
        insrc_only = []
        indst_only = []
        
        async def compare_two(f1, f2):
            h1 = hash_of_file(f1)
            h2 = hash_of_file(f2)
            return f1, f2, h1 != h2

        tasks = []
        for root, dirs, files in os.walk(src):
            for file in files:
                src_file = os.path.join(root, file)
                dst_file = os.path.join(dst, src_file[len(src)+1:])
                if os.path.exists(dst_file):
                    # Do this in parallel
                    tasks.append(asyncio.create_task(compare_two(src_file, dst_file)))
                else:
                    insrc_only.append(src_file)
        tasks = await asyncio.gather(*tasks)
        for f in tasks:
            f1, f2, r = f
            if r:
                print("Mismatch", f1, f2)
                modified.append((f1, f2))
        for root, dirs, files in os.walk(dst):
            for file in files:
                dst_file = os.path.join(root, file)
                src_file = os.path.join(src, dst_file[len(dst)+1:])
                if not os.path.exists(src_file):
                    indst_only.append(dst_file)

        return modified, insrc_only, indst_only

    '''
        Returns the files that changed.
        ```
            create_watchdot()
            compile()
            change_source_code()
            compile()

            changed = get_last_changed()
            # if bitcodes changed
            # verify(bc1, bc2)

        ```
    '''
    def get_last_changed(self):
        result = []
        for k, hashes in self.state.items():
            if len(hashes) == 1:
                result.append(k)
            else:
                if hashes[-1] != hashes[-2]:
                    result.append(k)

        return result

class LLVMCompilableUseCase(UseCase):

    def __init__(self, fixed_shadow=None):
        # The following two fields are used to avoid the compilation and testing proces of an already compiled and tested project
        self.compiled = False
        self.tested = False
        # This second one os used to create the temp comp folder
        self.fixed_shadow = fixed_shadow
        super().__init__()

    async def test(self, cwd):

        raise NotImplementedError()

    async def compile(self, cwd):

        raise NotImplementedError()


class TestLLVMCompilableUseCase(LLVMCompilableUseCase):

    def __init__(self):
        # call constructor
        super().__init__()
        self.initial_source_code = '''
        int main() {
            return 0;
        }
        '''

        self.changed_source_code = '''
        int main() {
            return 4;
        }
        '''

        self.source_code = self.initial_source_code
        f = open(os.path.join(os.path.dirname(__file__), "tests", "lib", "main.cpp"), "w")
        f.write(self.source_code)
        f.close()

    async def compile(self, cwd, source):
        print(f"Compiling {cwd}")
        f = open(os.path.join(os.path.join(cwd), "main.cpp"), "w")
        f.write(source)
        f.close()
        # lets call clang
        # use subprocess
        ch = subprocess.run(["clang",  "-save-temps", "-o", "main.o", "main.cpp"], cwd=cwd)


class CMPResult:

    def __init__(self):
        self.id = None # get a uuid here
        self.project_name = ""
        # Save the comparison results


async def compile_test_verify(project1: LLVMCompilableUseCase, project2: LLVMCompilableUseCase) -> CMPResult:
    pass
    # Compile the original
    # Compile the variant

    # Check if they compile


if __name__ == '__main__':
    import sys
    import os
    # logging.basicConfig(level=logging.DEBUG)

    TEST_FOLDER = os.path.abspath(os.path.dirname(__file__))
    TEST_FOLDER = os.path.join(TEST_FOLDER, "tests")

    TEST_LIB = os.path.join(TEST_FOLDER, "lib")

    uc = TestLLVMCompilableUseCase()
    # uc.set_init_state()

    async def mm():

        shadow1 = asyncio.create_task(uc.shadow(TEST_LIB))
        shadow2 = asyncio.create_task(uc.shadow(TEST_LIB))


        shadow1 = await shadow1
        t1 = asyncio.create_task(uc.compile(shadow1, uc.initial_source_code))
        shadow2 = await shadow2
        t2 = asyncio.create_task(uc.compile(shadow2, uc.changed_source_code))
        # changed_cource_code -> changed_compilable
        await t2
        await t1
        modified, insrc_only, indst_only = uc.compare_shadows(shadow1, shadow2)
        print("Modified", modified)


    asyncio.run(mm())

