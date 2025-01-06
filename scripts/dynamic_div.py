import subprocess
import os
import json
from enum import Enum

home = os.environ['HOME']

variants_dir = f'{home}/Galapagos/functions'
intel_pin_bin = f'{home}/pin/pin'
pintool = f'{home}/pin/instnames.so'
lang = 'c'
original = False


def run_variants():
    projects = ['alsa-lib', 'ffmpeg', 'libgcrypt', 'liboqs', 'libsodium', 'openssl']
    eq = {}
    with open('eq_variants.json', 'r') as eq_file:
        eq = json.load(eq_file)

    for proj in projects:
        # load functions_info
        with open(f'{variants_dir}/{proj}/functions_info.json', 'r') as info:
            functions_info = json.load(info)
            
            for i, fn in enumerate(functions_info):
                for lang in ['c', 'go']:
                    for j in range(10):
                        if not fn['name'] in eq[proj] or not lang in eq[proj][fn['name']] or not str(j) in eq[proj][fn['name']][lang]:
                            continue

                        exe = f'{variants_dir}/{proj}/variants/{lang}/{fn["name"]}-{j}-once-O0-debug'
                        try: 
                            #if lang == 'c':
                            instructions = subprocess.check_output([intel_pin_bin, '-t', pintool, '-fn', fn['name'], '--', exe], text=True, timeout=4) 
                            print([intel_pin_bin, '-t', pintool, '-fn', fn['name'], '--', exe]) 
                            #elif lang == 'go':
                            #    instructions = subprocess.check_output([intel_pin_bin, '-t', pintool, '-fn', fn['fn_bc_name_go'], '--', output], text=True, timeout=4) 
                            #    print([intel_pin_bin, '-t', pintool, '-fn', fn['fn_bc_name_go'], '--', output]) 
                            with open(f'dynamic/{fn["name"]}-{j}-{lang}', 'w+') as f:
                                f.write(instructions)
                        except Exception as e:
                            print(e)
                            continue
def main():
    run_variants()

if __name__ == '__main__':
    main()
