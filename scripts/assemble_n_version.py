import sys
import json
import subprocess

project = sys.argv[1]

workspace = '/home/javier/galapagos-clones'
linker_bin = '/home/javier/Galapagos/linker/build/linker'

flags = {
    'bug-1': ['-O2'], 
    'bug-2': ['-Os'], 
    'bug-3': ['-O3', '-flto', '-march=znver4'], 
        }

ccs = {
    'bug-1': 'clang-15', 
    'bug-2': 'clang', 
    'bug-3': 'clang-18', 
        }

def main():
    print(project)
    
    # find original bc
    original_bc = f'/home/javier/Galapagos/miscompilation/{project}/project/main.bc'
    print(original_bc)
    # find equivalent bcs
    variant_bcs = []
    with open('eq_variants_miscompilation.json', 'r') as eq:
        eq_variants = json.load(eq)
        c_variants = eq_variants[project]['foo']['c']
        for var in c_variants:
            variant_bc = f'/home/javier/Galapagos/miscompilation/{project}/function/variants/c/foo_{var}.bc'
            print(variant_bc)
            variant_bcs.append(variant_bc)

    # call linker
    ll_file = f'/home/javier/Galapagos/miscompilation/{project}/n-version/n-version.ll'
    args = [
        linker_bin, 
        '--function_name_in_input=foo',
        '--function_name_in_replacement=foo',
        '--sln',
        f'--output={ll_file}',
        original_bc, 
        *variant_bcs
    ]

    print(args)
    subprocess.check_output(args)

    if project == 'bug-1':
        # hack for clang-15 compatibility
        subprocess.check_output(["sed", "-i", "s/memory(argmem: readwrite)/argmemonly/g", ll_file])
        subprocess.check_output(["sed", "-i", "s/memory(argmem: write)/argmemonly/g", ll_file])
    # compile to .o
    o_file = f'/home/javier/Galapagos/miscompilation/{project}/project/main.o'
    args = [
        ccs[project],
        *(flags[project]),
        '-c',
        ll_file,
        '-o',
        o_file
    ]
    print(args)

    subprocess.check_output(args)

    # run make
    subprocess.check_output(['make'], cwd=f'/home/javier/Galapagos/miscompilation/{project}/project')

main()

