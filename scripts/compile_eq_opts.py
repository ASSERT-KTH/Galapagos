import json
import subprocess

linker_bin = '/home/javier/Galapagos/linker/build/linker'

def main():
    
    with open('eq_variants.json', 'r') as eq:
        eq_variants = json.load(eq)
    # find original bc
        for proj in eq_variants:
            for lang in ['c', 'go']:
                with open(f'../functions/{proj}/functions_info.json', 'r') as f:
                    f_info = json.load(f)
                    for i, fn in enumerate(f_info):
                        original_bc = f'/home/javier/Galapagos/functions/{proj}/{i}_{fn["name"]}.once.bc'
#                   print('Original variant:', original_bc)
                        if eq_variants[proj].get(fn['name']) == None or len(eq_variants[proj].get(fn['name'])[lang]) == 0 :
                            continue
                        for var in eq_variants[proj][fn['name']][lang]:
                            # find equivalent bcs
                            variant_bc = f'/home/javier/Galapagos/functions/{proj}/variants/{lang}/{i}_{fn["name"]}_{var}.bc'
    #                       print('Equivalent variant:', variant_bc)

            # call linker
                            ll_file = f'/home/javier/Galapagos/functions/{proj}/variants/{lang}/{fn["name"]}-{var}.once.ll'
                            args = [
                                linker_bin, 
                                f'--function_name_in_input={fn["name"]}',
                                f'--function_name_in_replacement={fn["name"] if lang == "c" else fn["fn_bc_name_go"]}',
                                f'{"--sld" if lang == "c" else "--cld"}',
                                f'--output={ll_file}',
                                original_bc, 
                                variant_bc
                            ]

                            print(args)
                            subprocess.check_output(args, stderr=subprocess.DEVNULL)
                            opts = ['-O0', '-O1', '-O2', '-O3']

                            for opt in opts:

                                # compile to .o
                                o_file = f'/home/javier/Galapagos/functions/{proj}/variants/{lang}/{fn["name"]}-{var}.once.o'
                                args = [
                                    'clang',
                                    '-c',
                                    ll_file,
                                    opt,
                                    '-o',
                                    o_file
                                ]
                                print(args)
                                subprocess.check_output(args)
                            

                                debug_file = f'/home/javier/Galapagos/functions/{proj}/variants/{lang}/{fn["name"]}-{var}-once{opt}-debug'
                                
                                args = [
                                    'clang',
                                    o_file,
                                    opt,
                                    '-o',
                                    debug_file
                                ]
                                print(args)
                                subprocess.check_output(args)

                                bin_file = f'/home/javier/Galapagos/functions/{proj}/variants/{lang}/{fn["name"]}-{var}-once{opt}'
                                args = [
                                    'strip',
                                    '-o',
                                    bin_file,
                                    debug_file
                                ]
                                print(args)
                                subprocess.check_output(args)
            
main()

