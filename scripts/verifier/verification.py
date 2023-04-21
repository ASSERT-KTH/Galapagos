import os
import shutil
import subprocess
import tempfile
import logging

DIRNAME = os.path.abspath(os.path.dirname(__file__)) 
DEBUG_FOLDER = os.path.join(DIRNAME, 'debug')

'''
    Abstract verifier class. Each verifier must implement the verify method.
'''
class Verifier:
    '''
        Receives two files and run the verification over them

        code1: file descriptor
        code2: file descriptor

        returns: Custom object if the codes are equal, None otherwise
    '''
    def verify(code1, code2):
        raise NotImplementedError
    
class AliveVerifier(Verifier):

    '''
        Creates an alive2 verifier instance. If debug is enabled, the verifier will save the output of alive2 to a file in the debug folder. 
        If do_function_extraction is enabled, the verifier will extract all functions from both files and will do a pairwise comparison in which the best result for verification will be returned.
    '''
    def __init__(self, debug = False, do_function_extraction = False):
        self.debug = debug
        self.do_function_extraction = do_function_extraction
        self.alive_tv_bin = os.path.join(DIRNAME, "alive", "build", "alive-tv")

    '''
        Receives two files and run the alive verification over them. Files should be LLVM IR codes.
    '''
    def verify(self, code1, code2):
        # TODO check if codes are LLVM IR or LLVM bitcode
        # If bitcode, then do the function extractions

        # create two temporary files
        logging.info(f"Creating temporary files for {code1.name} and {code2.name}")
        tmp1 = tempfile.NamedTemporaryFile(delete=False)
        tmp2 = tempfile.NamedTemporaryFile(delete=False)

        # copy the content of code1 and code2 to the temporary files
        shutil.copyfile(code1.name, tmp1.name)
        shutil.copyfile(code2.name, tmp2.name)
        
        if self.debug:
            # if debug enable copy the content of the temporary files to the debug folder
            # create the debug folder if it does not exist
            if not os.path.exists(DEBUG_FOLDER):
                logging.debug("Creating debug folder")
                os.makedirs(DEBUG_FOLDER, exist_ok=True)
            # just copy the files
            logging.debug(f"Copying {tmp1.name} and {tmp2.name} to debug folder")
            name1 = os.path.basename(code1.name)
            name2 = os.path.basename(code2.name)
            shutil.copy(tmp1.name, os.path.join(DEBUG_FOLDER, f'{name1}'))
            shutil.copy(tmp2.name, os.path.join(DEBUG_FOLDER, f'{name2}'))
        # run alive with the two files
        # if debug enabled save the output of alive to a file in the debug folder

        logging.info(f'Alive verifier for: {tmp1.name} {tmp2.name}')
        alive_output = subprocess.check_output([self.alive_tv_bin, tmp1.name, tmp2.name])
        alive_output = alive_output.decode('utf-8')
        # Parse the alive output
        
        logging.debug(f'Alive output: {alive_output}')
    
if __name__ == "__main__":
    # setting upo logging
    logging.basicConfig(level=logging.DEBUG)
    v = AliveVerifier(debug=True)
    code1 = open(os.path.join(DIRNAME, 'tests' ,'code1.ll'), 'r')
    code2 = open(os.path.join(DIRNAME, 'tests' ,'code2.ll'), 'r')
    code3 = open(os.path.join(DIRNAME, 'tests' ,'code3.ll'), 'r')

    # The one below should pass
    v.verify(code1, code2)
    # The one below should fail
    v.verify(code1, code3)
