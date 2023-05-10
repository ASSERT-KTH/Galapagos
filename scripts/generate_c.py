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
import toml
import verifier

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

'''
    Compiles the source code with a passed optimization level
    Returns a tuple: (filename, source code hash, machine code hash, llvm IR file)
'''
def llvm_pipeline(filepath, opt="O0", original_folder = "", generate_llvm_ir = False, skip_if_exist = True):
    filename = os.path.basename(filepath)
    if not os.path.exists(os.path.join(WORKSPACE, "rosetta_codes", original_folder, "compiled")):
        os.makedirs(os.path.join(WORKSPACE, "rosetta_codes", original_folder, "compiled"))
    
    if not os.path.exists(os.path.join(WORKSPACE, "rosetta_codes", original_folder, "compiled", "llvm")):
        os.makedirs(os.path.join(WORKSPACE, "rosetta_codes", original_folder, "compiled", "llvm"))

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
        if skip_if_exist and not os.path.exists(os.path.join(WORKSPACE, f'./rosetta_codes/{original_folder}/compiled/{filename}.{opt}.o')):
            subprocess.run(cmd, check=True)
        # If it compiles, then generate the LLVM IR for verification
        if generate_llvm_ir:
            cmd = [
            "clang",
                f"-{opt}",
                "-emit-llvm",
                "-S",
                os.path.join(WORKSPACE, filepath),
                "-o",
                os.path.join(WORKSPACE, f'./rosetta_codes/{original_folder}/compiled/llvm/{filename}.{opt}.ll')
            ]
            if skip_if_exist and not os.path.exists(os.path.join(WORKSPACE, f'./rosetta_codes/{original_folder}/compiled/llvm/{filename}.{opt}.ll')):

                subprocess.check_output(cmd)
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
            return (filename, hsh, hshsource, os.path.join(WORKSPACE, f'./rosetta_codes/{original_folder}/compiled/llvm/{filename}.{opt}.ll') if generate_llvm_ir else None)
    except Exception as e:
        # move to error folder
        shutil.copy(os.path.join(WORKSPACE, filepath), os.path.join(WORKSPACE, f'./rosetta_codes/{original_folder}/error/{filename}'))

        with open(os.path.join(WORKSPACE, "rosetta_codes", original_folder, "error", f"{filename}.{opt}.error.txt"), 'w') as new_file:
            new_file.write(f"{e}\n{traceback.format_exc()}")
        return (filename, None, None, None)

def main(args):

    config = toml.load(os.path.join(WORKSPACE, 'scripts', 'config.toml'))
    print(f"\nExecuting script with config: {config}")

    openai.api_key = open(os.path.join(DIRNAME, ".API_TOKEN")).read().strip()
    # programs = ['BIO_free', 'BN_CTX_get', 'BN_free', 'BN_new', 'EVP_PKEY_free']
    functions = config['functions']
    temperatures = config['temperatures']
    n = config['n']

    force_no_helpers = True
    force_same_signature = True

    prompt_intros = [
        'The following code describes an unspecified function.',
    ]
    
    prompt_instructions = [
        "Produce program transformations that slightly vary the behavior of the original function while maintaining its original functionality. Use them to provide a program variant."
    ]

    shared_remarks = "Do not output any other text apart from the function's code."

    if force_no_helpers:
        shared_remarks += " Do not create auxiliary nor helper functions."
    if force_same_signature:
        shared_remarks += " Maintain the function's signature."


    for function in functions:
        for temperature in temperatures:
            source_files_prefix = os.path.join(WORKSPACE, config['input_dir'], function)

            # read from file
            code = extract_source(f'{source_files_prefix}')
            # nl_description = extract_NL(f'{source_file}.md')
        
            print(f"\nTaking original function {function}")
            for pit, prompt_tuple in enumerate(zip(prompt_intros, prompt_instructions)):

                prompt = '\n'.join([prompt_tuple[0], code, prompt_tuple[1], shared_remarks])
                print(prompt)
                it = 0
                while it < n:
                    
                    try:
                        sys.stdout.write(f'\rGenerating variant for {function} with prompt {pit} and iteration {it}/{n - 1}')
                        response = openai.ChatCompletion.create(
                            model="gpt-4",
                            messages=[{"role": "user", "content": prompt}],
                            temperature=temperature,
                            # max_tokens=7
                        )

                        parsed = parse_response(response)
                        new_filename = f'{function}.p{pit}.y{temperature}.v{it}.c'
                        
                         # Create a folder names as the original for better structure
                        out_dir = os.path.join(WORKSPACE, config['output_dir'], function)
                        if not os.path.exists(out_dir):
                            os.makedirs(out_dir)

                        with open(os.path.join(out_dir, new_filename), 'w') as new_file:
                            new_file.write(parsed)
                        
                        sys.stdout.write(f'\rGenerated variant for {function} with prompt {pit} and iteration {it}/{n - 1}')
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