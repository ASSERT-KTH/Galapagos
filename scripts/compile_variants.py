import subprocess
import json
from generate_variants import WORKSPACE
import os
import os.path as path

CC = path.join(WORKSPACE, 'linker', 'deps', 'llvm-Release-build-go', 'bin', 'llvm-goc')
DIS = path.join(WORKSPACE, 'linker', 'deps', 'llvm-Release-build-go', 'bin', 'llvm-dis')
OPT = path.join(WORKSPACE, 'linker', 'deps', 'llvm-Release-build-go', 'bin', 'opt')

lang = 'go'
function_path = path.join(WORKSPACE, 'functions', 'liboqs')

def read_variants():
    with open(path.join(function_path, 'functions_info.json')) as f:
        return json.loads(f.read())

def compile_variants(variants):
    #for each variant
    for i, v in enumerate(variants):
        for j in range(10):
            source = path.join(function_path, 'variants', lang, f'{i}_{v["name"]}_{j}.{lang}')
            output = path.join(function_path, 'variants', lang, f'{i}_{v["name"]}_{j}.ll')
            command = [CC, '-c', '-S', '-emit-llvm', '-o', output, source] 
            try:
                subprocess.check_output(command)
            except Exception:
                print(f'failed to compile {source}')
                os.remove(output)


def strip_variants(variants):
    for i, v in enumerate(variants):
        for j in range(10):
            input = path.join(function_path, 'variants', lang, f'{i}_{v["name"]}_{j}.ll')
            if not path.exists(input):
                continue
            bc = path.join(function_path, 'variants', lang, f'{i}_{v["name"]}_{j}.bc')
            opt_command = [OPT, '-strip-debug', '-o', bc, input] 
            dis_command = [DIS, '-o', input, bc] 
            try:
                subprocess.check_output(opt_command)
                subprocess.check_output(dis_command)
            except Exception:
                print(f'failed to strip {input}')
compile_variants(read_variants())
strip_variants(read_variants())


