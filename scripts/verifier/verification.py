import os
import shutil
import subprocess
import tempfile
import logging
import re
import asyncio
import logging
import json

class CustomFormatter(logging.Formatter):

    grey = "\x1b[38;20m"
    yellow = "\x1b[33;20m"
    red = "\x1b[31;20m"
    bold_red = "\x1b[31;1m"
    reset = "\x1b[0m"
    format = "%(asctime)s - %(name)s - %(levelname)s - %(message)s (%(filename)s:%(lineno)d)"

    FORMATS = {
        logging.DEBUG: grey + format + reset,
        logging.INFO: grey + format + reset,
        logging.WARNING: yellow + format + reset,
        logging.ERROR: red + format + reset,
        logging.CRITICAL: bold_red + format + reset
    }

    def format(self, record):
        log_fmt = self.FORMATS.get(record.levelno)
        formatter = logging.Formatter(log_fmt)
        return formatter.format(record)

DIRNAME = os.path.abspath(os.path.dirname(__file__))
DEBUG_FOLDER = os.path.join(DIRNAME, 'debug')

'''
    Returns the Levenshtein distance between two strings
'''
async def levenshtein_distance(s1, s2):
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
    Returns all function names defined in the LLVM bitcode file
'''
def extract_all_defined_functions_from_bc(code1, llvm_dis="llvm-dis", debug=False):
    tmp = tempfile.NamedTemporaryFile(delete=False)
    subprocess.check_output([llvm_dis, "-o", tmp.name, code1.name])
    return extract_all_defined_functions(open(tmp.name, "r"), debug=debug)



'''
    Returns all function names defined in the LLVM IR file
'''
def extract_all_defined_functions(code1, debug=False):
    try:
        r = re.compile(r"define (.+) @(.+?)\(")
        llvm_ir = code1.read()
        if debug:
            logging.debug(f"Extracting functions from {code1.name}")
            name1 = f"{os.path.basename(code1.name)}.ll"
            shutil.copy(code1.name, os.path.join(DEBUG_FOLDER, f'{name1}'))

        function_names= []
        for m in r.finditer(llvm_ir):
            function_names.append(m.group(2))

        return function_names
    except UnicodeDecodeError as e:
        logging.warning(f"{e}\nInvalid file parsing. Trying to use llvm-dis to convert to text")
        return extract_all_defined_functions_from_bc(code1, debug=debug)


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
            self.errors = []

            import logging
            self._create_from_output()

            # set the formatter
            logger = logging.getLogger("root")
            logger.setLevel(logging.DEBUG)

            # create console handler with a higher log level
            ch = logging.StreamHandler()
            ch.setLevel(logging.DEBUG)

            ch.setFormatter(CustomFormatter())

            logger.addHandler(ch)
            logging = logger


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
                    # adding all errors so far
                    self.errors.append(l)
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

        def toDict(self):
            return { 'raw': self.alive_output, 'alive_falied': self.alive_failed(), 'failed_to_prove': self.failed_to_prove(), 'is_incorrect': self.is_incorrect(), 'is_ok': self.is_ok(), 'is_empty': self.is_empty(), 'errors': self.errors }

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
        self.linker_bin = "llvm-link"

    def _parse_result(self, alive_output):
        return AliveVerifier.AliveResult(alive_output)

    '''
        Receives two files and run the alive verification over them. Files should be LLVM IR codes or bitcodes.
        entrypoint: if not None, then the verifier will extract the function with the given name from both files. If None, the default behavoir of alive2 if to do a pairwise comparison based on the names
        timeout: timeout in seconds for the verification process. Default 10000
        target_fn: if not None, then the verifier will extract the function with the given name in the variant file (Notice that is based in our "modification" of alive2)
        src_fn: if not None, then the verifier will extract the function with the given name in the original file
    '''
    def verify(self, code1, code2, entrypoint, target_fn = None, src_fn = None, timeout=10000, alive_flags=[], estimate_target_fn = True):
        r = asyncio.run(self.async_verify(code1, code2, entrypoint, target_fn, src_fn, timeout, alive_flags, estimate_target_fn))

    '''
        The same of verify but async
    '''
    async def async_verify(self, code1, code2, entrypoint, target_fn = None, src_fn = None, timeout=60000, alive_flags=[], estimate_target_fn = True):

        # if debug enable copy the content of the temporary files to the debug folder
        # create the debug folder if it does not exist
        if not os.path.exists(DEBUG_FOLDER):
            logging.debug("Creating debug folder")
            os.makedirs(DEBUG_FOLDER, exist_ok=True)

        if target_fn is None:
            target_fn = entrypoint
        if src_fn is None:
            src_fn = entrypoint

        new_flags = [f for f in alive_flags]
        # This can be managed with alive itself
        # --func=<function name> , --src-fn=<string> , --tgt-fn=<string>, --tgt-unroll=<uint>
        # Extract entrypoint function and call verification again
        new_flags.append(f"--func={entrypoint}")
        new_flags.append(f"--src-fn={src_fn}")
        new_flags.append(f"--tgt-fn={target_fn}")


        # TODO check if codes are LLVM IR or LLVM bitcode
        # If bitcode, then do the function extractions ?

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

            # Just to save the ll
            if self.debug:
                extract_all_defined_functions(open(tmp1.name, "r"), debug=True)
                extract_all_defined_functions(open(tmp2.name, "r"), debug=True)
        # run alive with the two files
        # if debug enabled save the output of alive to a file in the debug folder

        logging.info(f'Alive verifier for: {tmp1.name} {tmp2.name}')


        try:
            logging.info(f"Calling alive for {code1.name} and {code2.name}")
            logging.info(f"Alive flags {new_flags}")
            alive_output = subprocess.check_output([self.alive_tv_bin, "--smt-to", f"{timeout}", *new_flags, tmp1.name, tmp2.name])
            alive_output = alive_output.decode('utf-8')
        except Exception as e:
            cmd = " ".join([self.alive_tv_bin, "--smt-to", f"{timeout}", *new_flags, tmp1.name, tmp2.name])
            logging.error(f"Error running alive: {e}")
            logging.error(f"Run {cmd}")
            return None
        # Parse the alive output

        r = self._parse_result(alive_output)
        if r.is_empty():
            logging.warning(f"Verify the entrypoint '{entrypoint}' for {name2}. Alive did not find any transformation")

            # This can be done because the the function names provide embedding. Thus the variant will maintain it in the end
            # Yet, lets throw a warning just in case
            if estimate_target_fn:
                # Estimate the closest function name to the current source function
                # get all functions from code2
                functions = extract_all_defined_functions(code2, debug=self.debug)
                # get the levensthein distances
                # TODO going parallel
                distances = [asyncio.create_task(levenshtein_distance(entrypoint, f)) for f in functions]
                distances = [await d for d in distances]
                # get the index of the minimum distance
                min_index = distances.index(min(distances))
                # get the function name
                target_fn = functions[min_index]
                logging.warning(f"Using {target_fn} as target function.")

                return await self.async_verify(code1, code2, entrypoint=entrypoint, src_fn=entrypoint, target_fn=target_fn, timeout=timeout, alive_flags=alive_flags, estimate_target_fn=False)

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


    code6 = open(os.path.join(DIRNAME, 'tests' ,'code4.bc'), 'r')
    code7 = open(os.path.join(DIRNAME, 'tests' ,'code5.bc'), 'r')

    # The one below should pass
    # r = v.verify(code1, code2)
    # assert r.is_ok()
    # The one below should fail
    # r = v.verify(code1, code3)
    # assert r.is_incorrect()

    # r = v.verify(code4, code5, entrypoint='quicksort')

    # v.verify(code6, code7, entrypoint="quicksort", estimate_target_fn=True)


    code8 = open(os.path.join(DIRNAME, 'tests' ,'bc1.eq.bc'), 'r')
    code7 = open(os.path.join(DIRNAME, 'tests' ,'bc2.eq.bc'), 'r')

    # The one below should pass
    # r = v.verify(code1, code2)
    # assert r.is_ok()
    # The one below should fail
    # r = v.verify(code1, code3)
    # assert r.is_incorrect()

    r = v.verify(code7, code8, entrypoint='bn_free_d', timeout=300000, alive_flags=['--smt-log', '--disable-undef-input'])
