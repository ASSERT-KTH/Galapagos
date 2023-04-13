import os
import sys
import openai
import subprocess
import distance_utils
import traceback    
import shutil
import hashlib

WORKSPACE = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
DIRNAME = os.path.abspath(os.path.dirname(__file__))

def extract_substitution_from_file(file):
    with open(file, 'r') as file:
        data = file.read()

        # lines = data.split('\n')

        # for i, l in enumerate(lines):
        #     if '<START SUBSTITUTION>' in l:
        #         start_line = i
        #     elif '<END SUBSTITUTION>' in l:
        #         end_line = i
        
        return data

def parse_response(resp):
    text = resp['choices'][0]['message']['content']

    parsed = text.replace('\\"', '"').replace('```c', '').replace('```C', '').replace('```','')

    return parsed

def pipeline(filepath, opt="O0"):
    filename = os.path.basename(filepath)
    if not os.path.exists(os.path.join(WORKSPACE, "rosetta_codes", "compiled")):
        os.mkdir(os.path.join(WORKSPACE, "rosetta_codes", "compiled"))
    

    if not os.path.exists(os.path.join(WORKSPACE, "rosetta_codes", "compiled", "objdump")):
        os.mkdir(os.path.join(WORKSPACE, "rosetta_codes", "compiled", "objdump"))

    if not os.path.exists(os.path.join(WORKSPACE, "rosetta_codes", "error")):
        os.mkdir(os.path.join(WORKSPACE, "rosetta_codes", "error"))

    cmd = [
        "clang",
        os.path.join(WORKSPACE, filepath),
        f"-{opt}",
        # TODO add here the optimization flags
        "-o",
        os.path.join(WORKSPACE, f'./rosetta_codes/compiled/{filename}.{opt}.o')
    ]


    # try to compile
    try:
        subprocess.run(cmd, check=True)
        # If it compiles, then we can objdump

        objcmd = [
            "objdump",
            "-d",
            os.path.join(WORKSPACE, f'./rosetta_codes/compiled/{filename}.{opt}.o')
        ]


        objdump = subprocess.check_output(objcmd)
        objdump = objdump.decode('utf-8')
        # Clean up the objdump
        # print(objdump)
        clean = distance_utils.clean_code(objdump)

        with open(os.path.join(WORKSPACE, "rosetta_codes", "compiled", "objdump", f"{filename}.{opt}.objdump"), 'w') as new_file:
            hsh = hashlib.sha256(clean.encode('utf-8')).hexdigest()
            print(filename, hsh)
            # TODO remove from here
            filesource = open(os.path.join(WORKSPACE, filepath), 'r').read()
            hshsource = hashlib.sha256(filesource.encode('utf-8')).hexdigest()
            new_file.write(clean)
            return (filename, hsh, hshsource)
    except Exception as e:
        # move to error folder
        shutil.copy(os.path.join(WORKSPACE, filepath), os.path.join(WORKSPACE, f'./rosetta_codes/error/{filename}'))

        with open(os.path.join(WORKSPACE, "rosetta_codes", "error", f"{filename}.{opt}.error.txt"), 'w') as new_file:
            new_file.write(f"{e}\n{traceback.format_exc()}")
        return (filename, None, None)

def synth_substitute(substitute_code, it):
    # with open(source_file, 'r') as file:
    #     data = file.read()
    #     lines = data.split('\n')

    #     for i, l in enumerate(lines):
    #         if '<START SUBSTITUTION>' in l:
    #             start_line = i
    #         elif '<END SUBSTITUTION>' in l:
    #             end_line = i
        
    #     new = '\n'.join([
    #         '\n'.join(lines[:start_line]), 
    #         substitute_code,
    #         '\n'.join(lines[end_line + 1:])
    #     ])

    with open(os.path.join(WORKSPACE, f'./rosetta_codes/quicksort.v{it}.c'), 'w') as new_file:
        new_file.write(substitute_code)

    

def main(args):
    n = 100

    source_file = os.path.join(WORKSPACE, 'rosetta_codes', 'quicksort.c')
    source = extract_substitution_from_file(source_file)

    # Read from file
    openai.api_key = open(os.path.join(DIRNAME, ".API_TOKEN")).read().strip()
    # algorithm = 'quicksort'
    # n = 3
    # language = 'golang'

    for it in range(20, n):

        prompt_intro = f'The following code describes an unspecified program.'

        code = source

        instruction = f'create a substitute implementation of the program, which is different but equivalent. It should be possible to directly replace the program and it should provide the same functionality.'

        # instruction_b = f'you are a software developer. You create a substitute implementation of the function `partition`. This substitute function must be different but semantically equivalent. It should be possible to directly replace the code in a program and it should provide the same functionality. Use the same function names.'
        
        prompt = '\n'.join([prompt_intro, code, instruction])

        response = openai.ChatCompletion.create(
            model="gpt-4",
            messages=[{"role": "user", "content": prompt}],
            temperature=1,
            # max_tokens=7
        )

        # print(response)
        parsed = parse_response(response)
        synth_substitute(parsed, it)


if __name__ == "__main__":

    main(sys.argv)