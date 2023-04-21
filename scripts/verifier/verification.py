import os
import shutil
import subprocess
import tempfile
import logging
import re

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

        returns: Custom object with validation results
    '''
    def verify(code1, code2):
        raise NotImplementedError
    
class AliveVerifier(Verifier):

    class AliveResult:
        
        def __init__(self, original_output) -> None:
            self.result = {}
            self.alive_output = original_output
            # regular expression to extract success/fail information
            # Ex: '0 correct transformations'
            self.alive_summary_output_regex = re.compile(r'((\d+) ((correct|incorrect|failed-to-prove) transformations|(Alive2 errors)))')
            self._create_from_output()


        def _create_from_output(self, ):
            lines = self.alive_output.splitlines()
            self.result = {}
            for l in lines:
                matches = self.alive_summary_output_regex.findall(l)
                if len(matches) > 0:
                    count = int(matches[0][1])
                    type = matches[0][2]
                    logging.info(f"Result matching {count} {type}")
                    self.result[type] = count
            # TODO parse the counter examples if errors
            logging.info(f"{self.result}")
            self.result

        '''
            Returns true if the verification was successful
        '''
        def is_ok(self):
            return self.result['correct transformations'] > 0
        
        '''
            Returns true if the verification failed
        '''
        def is_incorrect(self):
            return self.result['incorrect transformations'] > 0

        '''
            Returns true if the verification failed to prove
        '''
        def failed_to_prove(self):
            return self.result['failed-to-prove transformations'] > 0

        '''
            Returns true if alive2 failed
        '''
        def alive_failed(self):
            return self.result['Alive2 errors'] > 0

    '''
        Creates an alive2 verifier instance. If debug is enabled, the verifier will save the output of alive2 to a file in the debug folder. 
        If do_function_extraction is enabled, the verifier will extract all functions from both files and will do a pairwise comparison in which the best result for verification will be returned.
    '''
    def __init__(self, debug = False, do_function_extraction = False):
        # TODO: check alive-tv options and add them here in the constructor if needed
        self.debug = debug
        self.do_function_extraction = do_function_extraction
        self.alive_tv_bin = os.path.join(DIRNAME, "alive", "build", "alive-tv")


    def _parse_result(self, alive_output):
        return AliveVerifier.AliveResult(alive_output)
    
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
        return self._parse_result(alive_output)

    
if __name__ == "__main__":
    # setting upo logging
    logging.basicConfig(level=logging.DEBUG)
    v = AliveVerifier(debug=True)
    code1 = open(os.path.join(DIRNAME, 'tests' ,'code1.ll'), 'r')
    code2 = open(os.path.join(DIRNAME, 'tests' ,'code2.ll'), 'r')
    code3 = open(os.path.join(DIRNAME, 'tests' ,'code3.ll'), 'r')

    # The one below should pass
    r = v.verify(code1, code2)
    assert r.is_ok()
    # The one below should fail
    r = v.verify(code1, code3)
    assert r.is_incorrect()
