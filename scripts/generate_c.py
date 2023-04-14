import os
import sys
import openai
import subprocess
import distance_utils
import traceback    
import shutil
import hashlib
import re 
import time

WORKSPACE = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
DIRNAME = os.path.abspath(os.path.dirname(__file__))

def extract_source(file):
    with open(file, 'r') as file:
        data = file.read()
        return data

def parse_response(resp):
    text = resp['choices'][0]['message']['content']

    parsed = re.sub(r'```[Cc][Cc]?[Pp]?[Pp]?', '', text).replace('\\"', '"').replace('```','')

    return parsed

def pipeline(filepath, opt="O0", original_folder = ""):
    filename = os.path.basename(filepath)
    if not os.path.exists(os.path.join(WORKSPACE, "rosetta_codes", original_folder, "compiled")):
        os.makedirs(os.path.join(WORKSPACE, "rosetta_codes", original_folder, "compiled"))
    

    if not os.path.exists(os.path.join(WORKSPACE, "rosetta_codes",original_folder, "compiled", "objdump")):
        os.makedirs(os.path.join(WORKSPACE, "rosetta_codes",original_folder, "compiled", "objdump"))

    if not os.path.exists(os.path.join(WORKSPACE, original_folder, "rosetta_codes", "error")):
        os.makedirs(os.path.join(WORKSPACE, "rosetta_codes", original_folder, "error"))

    cmd = [
        "clang",
        os.path.join(WORKSPACE, filepath),
        f"-{opt}",
        # TODO add here the optimization flags
        "-o",
        os.path.join(WORKSPACE, f'./rosetta_codes/{original_folder}/compiled/{filename}.{opt}.o')
    ]


    # try to compile
    try:
        subprocess.run(cmd, check=True)
        # If it compiles, then we can objdump

        objcmd = [
            "objdump",
            "-d",
            os.path.join(WORKSPACE, f'./rosetta_codes/{original_folder}/compiled/{filename}.{opt}.o')
        ]


        objdump = subprocess.check_output(objcmd)
        objdump = objdump.decode('utf-8')
        # Clean up the objdump
        # print(objdump)
        clean = distance_utils.clean_code(objdump)

        with open(os.path.join(WORKSPACE, "rosetta_codes", original_folder, "compiled", "objdump", f"{filename}.{opt}.objdump"), 'w') as new_file:
            hsh = hashlib.sha256(clean.encode('utf-8')).hexdigest()
            print(filename, hsh)
            # TODO remove from here
            filesource = open(os.path.join(WORKSPACE, filepath), 'r').read()
            hshsource = hashlib.sha256(filesource.encode('utf-8')).hexdigest()
            new_file.write(clean)
            return (filename, hsh, hshsource)
    except Exception as e:
        # move to error folder
        shutil.copy(os.path.join(WORKSPACE, filepath), os.path.join(WORKSPACE, f'./rosetta_codes/{original_folder}/error/{filename}'))

        with open(os.path.join(WORKSPACE, "rosetta_codes", original_folder, "error", f"{filename}.{opt}.error.txt"), 'w') as new_file:
            new_file.write(f"{e}\n{traceback.format_exc()}")
        return (filename, None, None)

def synth_substitute(original, filename, substitute_code, it):
    # Create a folder names as the original for better structure
    if not os.path.exists(os.path.join(WORKSPACE, "rosetta_codes", original)):
        os.makedirs(os.path.join(WORKSPACE, "rosetta_codes", original))

    with open(os.path.join(WORKSPACE, f'./rosetta_codes/{original}/{filename}'), 'w') as new_file:
        new_file.write(substitute_code)

def main(args):

    openai.api_key = open(os.path.join(DIRNAME, ".API_TOKEN")).read().strip()
    programs = ['quicksort', 'md5' ]
    n = 3

    prompt_intros = [
        'The following code describes an unspecified program.',
        'I have the C code implementation in the following text'
    ]
    
    prompt_instructions = [
        'create a substitute implementation of the program, which is different but equivalent. It should be possible to directly replace the program and it should provide the same functionality.',
        'Give me a semantically equivalent version of the program in the same language. Do not output any other text apart from the code.'
    ]

    shared_remarks = 'Do not output any other text apart from the code.'

    for program in programs:
        source_files_prefix = os.path.join(WORKSPACE, 'rosetta_codes', program)

        # read from file
        code = extract_source(f'{source_files_prefix}.c')
        # nl_description = extract_NL(f'{source_file}.md')
    
        print(f"Taking original program {program}")
        for pit, prompt_tuple in enumerate(zip(prompt_intros, prompt_instructions)):

            prompt = '\n'.join([prompt_tuple[0], code, prompt_tuple[1], shared_remarks])
            it = 0
            while it < n:
                
                try:
                    sys.stdout.write(f'\rGenerating variant for {program} with prompt {pit} and iteration {it}/{n - 1}')
                    response = openai.ChatCompletion.create(
                        model="gpt-4",
                        messages=[{"role": "user", "content": prompt}],
                        temperature=1,
                        # max_tokens=7
                    )

                    parsed = parse_response(response)
                    new_filename = f'{program}.p{pit}.v{it}.c'
                    synth_substitute(program, new_filename, parsed, it)
                    sys.stdout.write(f'\rGenerated variant for {program} with prompt {pit} and iteration {it}/{n - 1}')
                    it += 1
                except KeyboardInterrupt:
                    break
                except Exception as e:
                    print(e)
                    print("Trying again in 5 mins")
                    # Sleep for 5 minutes
                    time.sleep(300)

if __name__ == "__main__":

    main(sys.argv)