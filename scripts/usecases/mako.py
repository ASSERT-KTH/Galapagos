
import usecases.case as case
import subprocess
import os
import asyncio
import logging
import traceback
import time

class mako(case.LLVMCompilableUseCase):

    def __init__(self, function_name, original_project_folder, original_file_location, variant_text_location, line_start, line_end, name="mako", doreplace=True, real_name=""):
        super().__init__()
        # TODO: add warning for needed packages/libraries for mako's compilations to work (?)
        # logging.warning("Make sure <stuff here> is installed in your system, otherwise the compilation of mako wont work")
        self.name = name
        self.function_name = function_name
        self.original_project_folder = original_project_folder
        self.variant_text_location = variant_text_location
        self.original_file_location = original_file_location
        self.change_location=(original_file_location, line_start, line_end)

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
            #logging.info("Setting up autogen")
            #ch = subprocess.check_output(["./autogen.sh"], env={**os.environ, "CFLAGS": "-save-temps", "CC": "clang", "CXX": "clang++", "CXXFLAGS": "-save-temps"},
            #    shell=True,
            #    cwd=cwd,
            #    stderr=subprocess.STDOUT)
            #logging.debug(ch.decode())
            logging.info("Calling configure")
            # TODO: change this to the correct flags?
            ch = subprocess.check_output(["./configure", "--cc=clang", "--extra-cflags=\"-emit-llvm\"", "--disable-x86asm"], env={**os.environ},
                shell=True,
                cwd=cwd,
                stderr=subprocess.STDOUT)

            logging.info("Calling make")
            try:
                ch = subprocess.check_output(["make", "-j", "16"], cwd=cwd, env={**os.environ}, stderr=subprocess.STDOUT)
                print(f"Compiled in {time.time() - start:.2f}s")
                self.compiled = True
            except Exception as e:
                print(e)
                # TODO: check if this is required here (and for the other libraries' use cases as well)
                # logging.warning(
                #     "Make sure the dependencies are installed\n" + '''
                #     sudo apt-get update -qq && sudo apt-get -y install \
                #     autoconf \
                #     automake \
                #     build-essential \
                #     cmake \
                #     git-core \
                #     libass-dev \
                #     libfreetype6-dev \
                #     libgnutls28-dev \
                #     libmp3lame-dev \
                #     libsdl2-dev \
                #     libtool \
                #     libva-dev \
                #     libvdpau-dev \
                #     libvorbis-dev \
                #     libxcb1-dev \
                #     libxcb-shm0-dev \
                #     libxcb-xfixes0-dev \
                #     meson \
                #     ninja-build \
                #     pkg-config \
                #     texinfo \
                #     wget \
                #     yasm \
                #     zlib1g-dev
                #     ''',

                #     )
                self.compiled = False
                raise e
        # block here?

