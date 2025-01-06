import json
import subprocess

linker_bin = '/home/javier/Galapagos/linker/build/linker'

def main():
    
    totals = {'c': {'bc': 0, '-O0': 0,'-O1': 0,'-O2': 0,'-O3': 0},
              'go': {'bc': 0, '-O0': 0,'-O1': 0,'-O2': 0,'-O3': 0}}

    with open('eq_variants.json', 'r') as eq:
        eq_variants = json.load(eq)
    # find original bc
        for proj in eq_variants:
            for lang in ['c', 'go']:
                with open(f'../functions/{proj}/functions_info.json', 'r') as f:
                    f_info = json.load(f)
                    for i, fn in enumerate(f_info):
                        if eq_variants[proj].get(fn['name']) == None or len(eq_variants[proj].get(fn['name'])[lang]) == 0 :
                            continue
                            
                        opts = ['bc', '-O0', '-O1', '-O2', '-O3']
                        for opt in opts:

                            s = set()
                            for var in eq_variants[proj][fn['name']][lang]:

                                
                                if opt == 'bc':


                                    args = [
                                        'opt',
                                        '--strip-debug',
                                        '--strip-named-metadata',
                                        '-o',
                                        f'/home/javier/Galapagos/functions/{proj}/variants/{lang}/{i}_{fn["name"]}_{var}.strip.bc',
                                        f'/home/javier/Galapagos/functions/{proj}/variants/{lang}/{fn["name"]}-{var}.once.ll',
                                    ]
    #                                print(args)
                                    subprocess.check_output(args)                                    
                                    args = [
                                        'sha256sum',
                                        f'/home/javier/Galapagos/functions/{proj}/variants/{lang}/{i}_{fn["name"]}_{var}.strip.bc'
                                    ]
    #                                print(args)
                                    sha256 = subprocess.check_output(args, text=True).split(' ')[0]
                                    s.add(sha256)

                                else:

                                    bin_file = f'/home/javier/Galapagos/functions/{proj}/variants/{lang}/{fn["name"]}-{var}-once{opt}'
                                    
                                    args = [
                                        'sha256sum',
                                        bin_file
                                    ]
    #                                print(args)
                                    sha256 = subprocess.check_output(args, text=True).split(' ')[0]
                                    s.add(sha256)

                            totals[lang][opt] += len(s)
                            print(proj, fn['name'], lang, opt, len(eq_variants[proj][fn['name']][lang]), len(s))

                        print(totals)

            
main()

