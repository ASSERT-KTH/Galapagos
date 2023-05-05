import watchdog
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
import asyncio

import hashlib
import shutil
import subprocess
import logging
import os

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

    def __init__(self):
        self.observer = None
        # The state is a map of the filepath vs hash of the file in time
        # A file changes if the last hash is != of the current hash
        # TODO move this to REDIS ?
        logging.info("Creating the empty state")
        self.state = {  }

    '''
        This will create a watchdog in a folder and report if something change. This will be helpful when a bitcode changes, we could map then a change from the source code to the
        compilation without going inside the compilation process.
        Notice that the watcher is asynchronous, so we need to use a loop to keep it running.
    '''
    async def create_watchdog(self, folder, check_interval=1):
        # Fill up the state with the initial state of the folder
        for root, dirs, files in os.walk(folder):
            for file in files:
                hsh = hash_of_file(os.path.join(root, file))
                if hsh:
                    self.state[os.path.join(root, file)] = [hsh]

        self.observer = Observer()
        self.observer.schedule(self, folder, recursive=True)
        self.observer.start()
        logging.info("Starting watchdog")

        try:
            while True:
                await asyncio.sleep(check_interval)
        except KeyboardInterrupt:
            self.observer.stop()

        self.observer.join()

    def on_modified(self, event):
        if event.is_directory:
            return None
        # only raise modified if the hash of the file changed !
        hsh = hash_of_file(event.src_path)
        if hsh and event.src_path in self.state:
            if self.state[event.src_path][-1] != hsh:
                self.state[event.src_path].append(hsh)
                self.on_modified_filtered(event, hsh)
            else:
                # TODO replace by a logging
                print(f"File modified but hash did not change: {event.src_path}")
        else:
            # Check if create is called first
            pass
            # create the state
            # self.state[event.src_path] = [hsh]


    '''
        This is the method to be implemented by the usecase clases to filter for example, bitcodes
    '''
    def on_modified_filtered(self, event, hash):
        pass
        #print(f"File modified: {event.src_path} {hash}")


    def on_created(self, event):
        if event.is_directory:
            return None
        # TODO only if the file did not exist before in the state !
        hsh = hash_of_file(event.src_path)
        if hsh:
            if event.src_path in self.state:
                if self.state[event.src_path][-1] != hsh:
                    self.state[event.src_path].append(hsh)
            else:
                self.state[event.src_path] = [hsh]
            self.on_created_filtered(event, hsh)


    def on_created_filtered(self, event, hash):
        # TODO only if the file did not exist before in the state !
        pass
        # print(f"File created: {event.src_path} {hash}")



    def on_deleted(self, event):
        if event.is_directory:
            return None

        # remove the file from the state
        hsh = hash_of_file(event.src_path)
        # TODO just mark to save what happens after
        # Do not check if exits...we do not care anyways
        # if event.src_path in self.state:
        #    del self.state[event.src_path]
        if hsh:
            self.on_deleted_filter(event, hsh)

    def on_deleted_filter(self, event, hash):
        print(f"File deleted: {event.src_path} {hash}")




    def on_moved(self, event):
        if event.is_directory:
            return None

        # TODO create and alias
        hsh = hash_of_file(event.dest_path)
        # Copy the state
        if hsh and event.src_path in self.state:
            self.state[event.dest_path] = self.state[event.src_path]
            self.on_moved_filtered(event, hsh)

    def on_moved_filtered(self, event, hash):
        print(f"File moved: {event.src_path} -> {event.dest_path} {hash}")


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

    def __init__(self):
        super().__init__()

    def compile(self):

        raise NotImplementedError()


class TestLLVMCompilableUseCase(LLVMCompilableUseCase):

    def __init__(self, lib_folder):
        # call constructor
        super().__init__()
        self.lib_folder = lib_folder
        self.initial_source_code = '''
        int main() {
            return 0;
        }
        '''

        self.changed_source_code = '''
        int main() {
            return 3;
        }
        '''

        self.source_code = self.initial_source_code

    def compile(self):
        print("Compiling")
        f = open(os.path.join(self.lib_folder, "main.cpp"), "w")
        f.write(self.source_code)
        f.close()
        # lets call clang
        # use subprocess
        ch = subprocess.run(["clang",  "-save-temps", "-o", "main.o", "main.cpp"], cwd=self.lib_folder)

    def set_init_state(self):
        self.source_code = self.initial_source_code
        self.compile()

    def change_source_code(self):
        print("Changing source code")
        self.source_code = self.changed_source_code




if __name__ == '__main__':
    import sys
    import os
    # logging.basicConfig(level=logging.DEBUG)

    TEST_FOLDER = os.path.abspath(os.path.dirname(__file__))
    TEST_FOLDER = os.path.join(TEST_FOLDER, "tests")

    TEST_LIB = os.path.join(TEST_FOLDER, "lib")

    uc = TestLLVMCompilableUseCase(TEST_LIB)
    uc.set_init_state()

    async def mm():
        t = asyncio.create_task(uc.create_watchdog(TEST_LIB))
        await asyncio.sleep(2)
        changed_source_codes = uc.get_last_changed()
        # print(changed_source_codes)
        # print([(c,uc.state[c]) for c in changed_source_codes if c.endswith(".cpp") or c.endswith(".bc") or c.endswith(".o")])
        # uc.compile()
        # change the source code
        uc.change_source_code()
        uc.compile()
        changed_compilable = uc.get_last_changed()

        print([(c, uc.state[c]) for c in changed_compilable if c.endswith(".cpp") or c.endswith(".bc") or c.endswith(".o")])
        # changed_cource_code -> changed_compilable


    asyncio.run(mm())

