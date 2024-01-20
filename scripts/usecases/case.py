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


# TODO: have a dictionary which maps libraries to their respective warnings, dependencies, compilation flags, etc.

LIBRARY_INFO = {
    "ffmpeg": {
        "dependencies": [
            "autoconf",
            "automake",
            "build-essential",
            "cmake",
            "git-core",
            "libass-dev",
            "libfreetype6-dev",
            "libgnutls28-dev",
            "libmp3lame-dev",
            "libsdl2-dev",
            "libtool",
            "libva-dev",
            "libvdpau-dev",
            "libvorbis-dev",
            "libxcb1-dev",
            "libxcb-shm0-dev",
            "libxcb-xfixes0-dev",
            "meson",
            "nasm",
            "ninja-build",
            "pkg-config",
            "texinfo",
            "wget",
            "yasm",
            "zlib1g-dev"
        ],
        "flags": [
            "--cc=clang",
            "--extra-cflags=\"-emit-llvm\"",
            "--disable-x86asm"
        ],
        "env": {
            "CFLAGS": "-save-temps",
            "CC": "clang",
            "CXX": "clang++",
            "CXXFLAGS": "-save-temps"
        },
        "configure": "./Configure",
    },
    "openssl": {
        "dependencies": [
            # TODO
        ],
        "flags": [
            "--cc=clang",
            "--extra-cflags=\"-emit-llvm\"",
            "--disable-x86asm"
        ],
        "env": {
            "CFLAGS": "-save-temps",
            "CC": "clang",
            "CXX": "clang++",
            "CXXFLAGS": "-save-temps"
        },
        "configure": "./configure",
    },
    "libsodium": {
        "dependencies": [
            # TODO
        ],
        "flags": [
            "--cc=clang",
            "--extra-cflags=\"-emit-llvm\"",
            "--disable-x86asm"
        ],
        "env": {
            "CFLAGS": "-save-temps",
            "CC": "clang",
            "CXX": "clang++",
            "CXXFLAGS": "-save-temps"
        },
        "configure": "./configure",
    },
    # TODO: mako, coreutils
}

DEPENDENCY_WARNING_TEMPLATE = '''
Make sure the required dependencies are installed\n
sudo apt-get update -qq && sudo apt-get -y install \\
{dependencies}
'''



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
                # print("Mismatch", f1, f2)
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

        # Not all projects have tests :(
        return True, None

    async def compile(self, cwd):

        raise NotImplementedError()

# TODO: rename this
class LibraryCompilableUseCase(LLVMCompilableUseCase):

    def __init__(self, function_name, original_project_folder, original_file_location, variant_text_location, line_start, line_end, name="ffmpeg", doreplace=True, real_name=""):
        super().__init__()
        self.name = name
        self.function_name = function_name
        self.original_project_folder = original_project_folder
        self.variant_text_location = variant_text_location
        self.original_file_location = original_file_location
        self.change_location = (original_file_location, line_start, line_end)

        self.test_result = None
        self.real_name = real_name
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
                # TODO: check this below;;;
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
            ch = subprocess.check_output(
                ["./autogen.sh", "-s"],
                env={**os.environ, **LIBRARY_INFO[self.name]["env"]},
                shell=True,
                cwd=cwd,
                stderr=subprocess.STDOUT
            )
            logging.debug(ch.decode())

            logging.info("Calling configure")
            ch = subprocess.check_output(
                [*LIBRARY_INFO[self.name]["configure"], *LIBRARY_INFO[self.name]["flags"]],
                env={**os.environ, **LIBRARY_INFO[self.name]["env"]},
                shell=True,
                cwd=cwd,
                stderr=subprocess.STDOUT
            )

            logging.info("Calling make")
            try:
                ch = subprocess.check_output(["make", "-j", "16"], cwd=cwd, env={**os.environ}, stderr=subprocess.STDOUT)
                print(f"Compiled in {time.time() - start:.2f}s")
                self.compiled = True
            except Exception as e:
                print(e)
                # TODO: check if this call works (currently untested)
                logging.warning(
                    DEPENDENCY_WARNING_TEMPLATE.format(
                        dependencies="\n".join(LIBRARY_INFO[self.name]["dependencies"])
                    )
                )
                self.compiled = False
                raise e
        # block here?

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

