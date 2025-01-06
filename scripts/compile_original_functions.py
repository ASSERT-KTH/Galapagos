import subprocess
import json
from generate_variants import WORKSPACE
from split_variants import read_params
import os
import os.path as path


functions = {}

def read_variants(function_path):
    with open(path.join(function_path, 'functions_info.json')) as f:
        return json.loads(f.read())

def compile_variants(variants, lang, function_path):
    #for each variant
    for i, v in enumerate(variants):
        
        functions[v['name']] = {}

        source = path.join(function_path, f'{i}_{v["name"]}.run.once.c')
        output1 = path.join(function_path, f'{v["name"]}.once.bc')
        output2 = path.join(function_path, f'{i}_{v["name"]}-once')
        command1 = ['clang', '-c', '-emit-llvm', '-o', output1, source] 
        command2 = ['clang', '-O0', '-o', output2, source] 
        try:
            subprocess.check_output(command1)
            subprocess.check_output(command2)
            
     #       print(output2)
     #       out = subprocess.check_output(output2)
     #       functions[v['name']]['cycles_baseline'] = float(out)
        except Exception as e:
            print(f'failed to compile {source}; {e}')
 #           try:
 #               os.remove(output1)
 #               os.remove(output2)
 #           except OSError:
 #               pass

lang, project = read_params()

function_path = path.join(WORKSPACE, 'functions', project)

compile_variants(read_variants(function_path), lang, function_path)

# with open(f'perf/{project}.json', 'w+') as f:
#     json.dump(functions, f, indent=4)
