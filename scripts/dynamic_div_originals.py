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
                try: 
                    binary = f'{variants_dir}/{proj}/{i}_{fn["name"]}-once'
                    instructions = subprocess.check_output([intel_pin_bin, '-t', pintool, '-fn', fn['name'], '--', binary], text=True, timeout=4) 
                    print([intel_pin_bin, '-t', pintool, '-fn', fn['name'], '--', binary]) 
                    with open(f'dynamic/{fn["name"]}-original', 'w+') as f:
                        f.write(instructions)
                except Exception as e:
                    print(e)
                    continue
def main():
    run_variants()

if __name__ == '__main__':
    main()
