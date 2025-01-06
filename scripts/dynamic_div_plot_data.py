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

func_dict = {
    #'alsa-lib'  : {'fn': '0_alaw_to_s16',         'variants': {f'c': 1, 'go': 1}, 'goname': 'main.alawToS16'},
    'ffmpeg'    : {'fn': '1_mix',                 'variants': {f'c': 7, 'go': 2}, 'goname': 'main.mix'},
    #'libgcrypt' : {'fn': '4_montgomery_reduce',   'variants': {f'c': 1, 'go': 1}, 'goname': 'main.montgomeryReduce'},
    #'liboqs'    : {'fn': '4_int16_nonzero_mask',  'variants': {f'c': 0, 'go': 0}, 'goname': 'main.int16_nonzero_mask'},
    #'libsodium' : {'fn': '4_fBlaMka',           'variants': {f'c': 2}},
    #'openssl'   : {'fn': '0_icbrt64',             'variants': {f'c': 9, 'go': 1}, 'goname': 'main.icbrt64'}
    }

def run_variants():
    for proj in func_dict:
        if original:
            driver = f'{variants_dir}/{proj}/{func_dict[proj]["fn"]}'
            fn_name = '_'.join(func_dict[proj]["fn"].split('_')[1:])
            instructions = subprocess.check_output([intel_pin_bin, '-t', pintool, '-fn', fn_name, '--', driver], text=True) 
            with open(f'dynamic/{fn_name}-original', 'w+') as f:
                f.write(instructions)
        else:
            output = f'{variants_dir}/{proj}/variants/{lang}/{func_dict[proj]["fn"]}_{func_dict[proj]["variants"][lang]}'
            source = f'{variants_dir}/{proj}/variants/{lang}/{func_dict[proj]["fn"]}_{func_dict[proj]["variants"][lang]}.{lang}'
            if lang == 'c':
                subprocess.check_output(['clang', '-o', output, source])
            elif lang == 'go':
                subprocess.check_output(['go', 'build', '-gcflags=-l', '-o', output, source])

            fn_name = '_'.join(func_dict[proj]["fn"].split('_')[1:])
            print([intel_pin_bin, '-t', pintool, '-fn', fn_name, '--', output]) 
            
            if lang == 'c':
                instructions = subprocess.check_output([intel_pin_bin, '-t', pintool, '-fn', fn_name, '--', output], text=True) 
            elif lang == 'go':
                instructions = subprocess.check_output([intel_pin_bin, '-t', pintool, '-fn', func_dict[proj]['goname'], '--', output], text=True) 
            with open(f'dynamic/{fn_name}-{lang}', 'w+') as f:
                f.write(instructions)

def main():
    run_variants()

if __name__ == '__main__':
    main()
