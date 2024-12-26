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
                        variant_bcs = []
                        original_bc = f'/home/javier/Galapagos/functions/{proj}/{i}_{fn['name']}.bc'
#                   print('Original variant:', original_bc)
                        if eq_variants[proj].get(fn['name']) == None or len(eq_variants[proj].get(fn['name'])[lang]) == 0 :
                            continue
                        for var in eq_variants[proj][fn['name']][lang]:
                            # find equivalent bcs
                            variant_bc = f'/home/javier/Galapagos/functions/{proj}/variants/{lang}/{i}_{fn['name']}_{var}.bc'
#                       print('Equivalent variant:', variant_bc)
                            variant_bcs.append(variant_bc)

            # call linker
                        ll_file = f'/home/javier/Galapagos/functions/{proj}/variants/{lang}/{fn['name']}-n-version.ll'
                        args = [
                            linker_bin, 
                            f'--function_name_in_input={fn["name"]}',
                            f'--function_name_in_replacement={fn["name"] if lang == 'c' else fn["fn_bc_name_go"]}',
                            f'{"--sln" if lang == 'c' else "--cln"}',
                            f'--output={ll_file}',
                            original_bc, 
                            *variant_bcs
                        ]

                        print(args)
                        subprocess.check_output(args, stderr=subprocess.DEVNULL)

                        # compile to .o
                        o_file = f'/home/javier/Galapagos/functions/{proj}/variants/{lang}/{fn["name"]}-n-version.o'
                        args = [
                            'clang',
                            '-c',
                            ll_file,
                            '-o',
                            o_file
                        ]
                        print(args)

                        subprocess.check_output(args)

                        bin_file = f'/home/javier/Galapagos/functions/{proj}/variants/{lang}/{fn["name"]}-n-version'
                        
                        args = [
                            'clang',
                            o_file,
                            '-o',
                            bin_file
                        ]
                        print(args)

                        subprocess.check_output(args)

                        out = subprocess.check_output(bin_file)

                        with open(f'perf/{proj}.json', 'r+') as g:
                            data = json.load(g)
                            g.seek(0)
                            data[fn['name']][f'{lang}_cycles_nversion'] = float(out)
                            data[fn['name']][f'{lang}_versions'] = len(variant_bcs)
                            json.dump(data, g, indent=4)
            
main()

