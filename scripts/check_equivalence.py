import json
import subprocess

def main():
    with open('eq_variants.json', 'r') as f:
        eq = json.load(f)

        projects = eq.keys()

        for proj in projects:
            functions = eq[proj].keys()

            for fn in functions:
                for lang in ['c', 'go']:
                    versions = eq[proj][fn][lang]

                    for n in range(len(versions)):
                            source_file = f'/home/javier/Galapagos/functions/{proj}/variants/{lang}/{fn}-n-version.ll'
                            target_file = f'/home/javier/Galapagos/functions/{proj}/variants/{lang}/{fn}-n-version.ll'
                            # /home/javier/Galapagos/functions/libgcrypt/variants/c/ctz-n-version.ll'
                            args = [
                                '/home/javier/Galapagos/scripts/verifier/alive/build/alive-tv',
                                f'--src-fn=version_1',
                                f'--tgt-fn=version_{n+2}', 
                                '--src-unroll=64',
                                '--tgt-unroll=64',
                                '--bidirectional',
                                '--smt-to=600000',
                                '--quiet',
                                source_file,
                                target_file
                            ]
                            print(proj, fn, lang, n+2, versions[n])
                            out = subprocess.check_output(args)
                            print(out)

main()
