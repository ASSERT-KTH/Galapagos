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
    print(resp)
    text = resp.choices[0].message.content

    parsed = re.sub(r'```[CcGg][CcOo]?[Pp]?[Pp]?', '', text).replace('\\"', '"').replace('```','')

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
    projects = config['projects']
    temperatures = config['temperatures']
    input_lang = config['input_lang']
    output_lang = config['output_lang']
    n_variants = config['n_variants']

    output_lang_opt = 'in the <OUTPUT> language'

    prompt_intro = 'The following code is a reference implementeation of a function in <INPUT>.'
    
    prompt_instructions = 'Create <NUMBER> substitute implementation(s) of the function, which are different but equivalent <OUTPUT_LANG>. It should be possible to directly replace the function and it should provide the same functionality'

    remarks = "int in C is equal to int32 in Go. Do not output any other text apart from code. Do not create auxiliary or helper functions. Maintain the original function's signature."
            

    for project in projects:
        files = os.listdir(os.path.join(WORKSPACE, 'functions', project))
        # filer .c files only
        allowlist = ['0_icbrt64.c']
        functions = [f for f in files if f.endswith('.c') and f in allowlist]
        for function in functions:
            for temperature in temperatures:
                function_file = os.path.join(WORKSPACE, 'functions', project, function)

                # read from file
                code = extract_source(f'{function_file}')
                # nl_description = extract_NL(f'{source_file}.md')
            
                print(f"\nTaking original function {function}")
                
                if input_lang != output_lang:
                    lang_opt = output_lang_opt.replace('<OUTPUT>', output_lang)
                else:
                    lang_opt = ''
                processed_intro = prompt_intro.replace('<INPUT>', input_lang)

                processed_instructions = prompt_instructions.replace('<NUMBER>', str(n_variants))
                processed_instructions = processed_instructions.replace('<OUTPUT_LANG>', lang_opt)
                prompt = '\n'.join([processed_intro, code, processed_instructions, remarks])
                print(prompt)
                        
                try:
                    sys.stdout.write(f'\rGenerating variants for {function}.')
                    response = openai.chat.completions.create(
                        model="gpt-4o",
                        messages=[{"role": "user", "content": prompt}],
                        temperature=temperature,
                        max_tokens=4096
                    )

                    parsed = parse_response(response)
                    new_filename = f'{function}.variants'
                    
                    # Create a folder names as the original for better structure
                    out_dir = os.path.join(WORKSPACE, 'functions', project, 'variants', output_lang.lower())
                    if not os.path.exists(out_dir):
                        os.makedirs(out_dir)

                    with open(os.path.join(out_dir, new_filename), 'w') as new_file:
                        new_file.write(parsed)
                    
                    sys.stdout.write(f'\rGenerated variants for {function}.')
                except KeyboardInterrupt:
                    break
                except Exception as e:
                    print(e)
                    print("Trying again in 5 mins")
                    # Sleep for 5 minutes
                    time.sleep(300)

if __name__ == "__main__":

    main(sys.argv)
