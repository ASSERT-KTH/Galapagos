import os
import shutil
import subprocess
import tempfile
import logging
import re

DIRNAME = os.path.abspath(os.path.dirname(__file__)) 
DEBUG_FOLDER = os.path.join(DIRNAME, 'debug')

'''
    Returns the Levenshtein distance between two strings
'''
def levenshtein_distance(s1, s2):
    if len(s1) > len(s2):
        s1, s2 = s2, s1

    distances = range(len(s1) + 1)
    for i2, c2 in enumerate(s2):
        distances_ = [i2+1]
        for i1, c1 in enumerate(s1):
            if c1 == c2:
                distances_.append(distances[i1])
            else:
                distances_.append(1 + min((distances[i1], distances[i1 + 1], distances_[-1])))
        distances = distances_
    return distances[-1]

'''
    Returns all function names defined in the LLVM IR file
'''
def extract_all_defined_functions(code1):
    r = re.compile(r"define (.+) @(.+?)\(")
    llvm_ir = code1.read()
    function_names= []
    for m in r.finditer(llvm_ir):
        function_names.append(m.group(2))

    return function_names

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
            self.alive_error_regex = re.compile(r'ERROR: (.+?)')
            self.error = None
            
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
                matches = self.alive_error_regex.findall(l)
                if len(matches) > 0:
                    self.error = l
            # TODO parse the counter examples if errors
            logging.info(f"{self.result}")
            self.result



        '''
            Returns true if all verification values are zero. This probably means that alive could not find the target function due to renaming.
        '''
        def is_empty(self):
            # Is ok if all passed and no errors
            return self.result['correct transformations'] == 0 and self.result['incorrect transformations'] == 0 and self.result['failed-to-prove transformations'] == 0 and self.result['Alive2 errors'] == 0


        '''
            Returns true if the verification was successful
        '''
        def is_ok(self):
            # Is ok if all passed and no errors
            return self.result['correct transformations'] > 0 and self.result['incorrect transformations'] == 0 and self.result['failed-to-prove transformations'] == 0 and self.result['Alive2 errors'] == 0
        
        '''
            Returns true if the verification failed
        '''
        def is_incorrect(self):
            return self.result['incorrect transformations'] > 0 or self.failed_to_prove() or self.alive_failed()

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
        self.extract_bin = "llvm-extract"


    def _parse_result(self, alive_output):
        return AliveVerifier.AliveResult(alive_output)
    
    '''
        Receives two files and run the alive verification over them. Files should be LLVM IR codes.
        entrypoint: if not None, then the verifier will extract the function with the given name from both files. If None, the default behavoir of alive2 if to do a pairwise comparison based on the names
        timeout: timeout in seconds for the verification process. Default 10000
    '''
    def verify(self, code1, code2, entrypoint=None, target_fn = None, src_fn = None, timeout=60, alive_flags=[], estimate_target_fn = False, solve_diff_names = False):

        # if debug enable copy the content of the temporary files to the debug folder
        # create the debug folder if it does not exist
        if not os.path.exists(DEBUG_FOLDER):
            logging.debug("Creating debug folder")
            os.makedirs(DEBUG_FOLDER, exist_ok=True)

        # TODO, move this to alive2 itself. Right now this filter is done by perfect matching between function names. We can do a Lev distance threshold instead.
        if solve_diff_names:
            # Do a pairwise comparison of all functions from original and replace the names in the code2 file
            tmp3 = f"{DEBUG_FOLDER}/{os.path.basename(code2.name)}.renamed.ll"
            content = open(code2.name, "r").read()
            tmp3f = open(tmp3, "wb")
            tmp3f.write(content.encode("utf-8"))

            for f in extract_all_defined_functions(code1):
                code2 = open(tmp3, 'r')

                logging.info(f"Replacing function {f}")
                functions_in2 = extract_all_defined_functions(code2)
                # get the distances
                distances = [levenshtein_distance(f1, f) for f1 in functions_in2]
                # get the index of the minimum distance
                min_index = distances.index(min(distances))
                # get the function name
                min_function = functions_in2[min_index]
                # replace the function name
                
                code2 = open(tmp3, 'r')
                content = code2.read().replace(min_function, f)
                # print(content)

                tmp3f = open(tmp3, "wb")
                tmp3f.write(content.encode('utf-8'))
                tmp3f.close()


            tmp3f = open(tmp3, "r")
            return self.verify(code1, tmp3f, entrypoint, target_fn, src_fn, timeout, alive_flags, estimate_target_fn, False)
        if target_fn is None:
            target_fn = entrypoint
        if src_fn is None:
            src_fn = entrypoint

        new_flags = [f for f in alive_flags]
        if entrypoint:
            # This can be managed with alive itself
            # --func=<function name> , --src-fn=<string> , --tgt-fn=<string>, --tgt-unroll=<uint>
            # Extract entrypoint function and call verification again
            new_flags.append(f"--src-fn={src_fn}")
            new_flags.append(f"--func={target_fn}")
            new_flags.append(f"--func={entrypoint}")

            
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
            # just copy the files
            logging.debug(f"Copying {tmp1.name} and {tmp2.name} to debug folder")
            name1 = os.path.basename(code1.name)
            name2 = os.path.basename(code2.name)
            shutil.copy(tmp1.name, os.path.join(DEBUG_FOLDER, f'{name1}'))
            shutil.copy(tmp2.name, os.path.join(DEBUG_FOLDER, f'{name2}'))
        # run alive with the two files
        # if debug enabled save the output of alive to a file in the debug folder

        logging.info(f'Alive verifier for: {tmp1.name} {tmp2.name}')
        

        try:
            logging.info(f"Calling alive for {code1.name} and {code2.name}")
            logging.info(f"Alive flags {new_flags}")
            alive_output = subprocess.check_output([self.alive_tv_bin, "--smt-to", f"{timeout}", *new_flags, tmp1.name, tmp2.name])
            alive_output = alive_output.decode('utf-8')
        except Exception as e:
            logging.error(f"Error running alive: {e}")
            return None
        # Parse the alive output

        r = self._parse_result(alive_output)
        if r.is_empty():
            logging.warning(f"Verify the entrypoint '{entrypoint}' for {name2}. Alive did not find any transformation")

            if estimate_target_fn:
                # Estimate the closest function name to the current source function
                # get all functions from code2
                functions = extract_all_defined_functions(code2)
                # get the levensthein distances
                distances = [levenshtein_distance(entrypoint, f) for f in functions]
                # get the index of the minimum distance
                min_index = distances.index(min(distances))
                # get the function name
                target_fn = functions[min_index]
                logging.warning(f"Using {target_fn} as target function. Renaming in the {code2.name} file")
                
                # Reopen to set the file pointer
                code2 = open(code2.name, "r")
                tmp3 = f"{DEBUG_FOLDER}/{os.path.basename(code2.name)}.renamed.ll"
                tmp3f = open(tmp3, "wb")
                content = code2.read().replace(target_fn, entrypoint)
                tmp3f.write(content.encode('utf-8'))
                tmp3f.close()

                tmp3f = open(tmp3, "r")

                return self.verify(code1, tmp3f, entrypoint=entrypoint, timeout=timeout, alive_flags=alive_flags, estimate_target_fn=False)
            
        if self.debug:
            # Save the output of alive to a file in the debug folder
            dst = "Ok"

            if r.is_empty():
                dst = "Empty"
            elif r.alive_failed():
                dst = "AliveFailed"
            elif r.failed_to_prove():
             dst = "FailedToProve"
            elif r.is_incorrect():
                dst = "Incorrect"

            if not os.path.exists(os.path.join(DEBUG_FOLDER, f"{name1}cmp", dst)):
                os.makedirs(os.path.join(DEBUG_FOLDER, f"{name1}cmp", dst), exist_ok=True)

            alive_output_file = os.path.join(DEBUG_FOLDER, f"{name1}cmp", dst, f'{name2}.alive.txt')
            logging.debug(f"Saving alive output to {alive_output_file}")

            # TODO Separate per into folders for better searching of errors
            with open(alive_output_file, 'w') as f:
                f.write(alive_output)

        return r

    
if __name__ == "__main__":
    # setting upo logging
    logging.basicConfig(level=logging.DEBUG)
    v = AliveVerifier(debug=True)
    code1 = open(os.path.join(DIRNAME, 'tests' ,'code1.ll'), 'r')
    code2 = open(os.path.join(DIRNAME, 'tests' ,'code2.ll'), 'r')
    code3 = open(os.path.join(DIRNAME, 'tests' ,'code3.ll'), 'r')

    code4 = open(os.path.join(DIRNAME, 'tests' ,'code4.ll'), 'r')
    code5 = open(os.path.join(DIRNAME, 'tests' ,'code5.ll'), 'r')

    # The one below should pass
    # r = v.verify(code1, code2)
    # assert r.is_ok()
    # The one below should fail
    # r = v.verify(code1, code3)
    # assert r.is_incorrect()

    r = v.verify(code4, code5, entrypoint='quicksort')