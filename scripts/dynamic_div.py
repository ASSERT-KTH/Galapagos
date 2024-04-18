import subprocess
import os
import json
from enum import Enum

home = os.environ['HOME']

clones_dir = f'{home}/galapagos-clones'
verification_output_dir = f'{home}/Galapagos/scripts/out' # ./out
intel_pin_bin = f'{home}/intel-pin/pin-3.30-98830-g1d7b601b3-gcc-linux/pin'
pintool = f'{home}/Galapagos/scripts/pintool/instnames.so'

class ModifyMode(Enum):
    INSERT_IN_LINE = 1

class TestRunMode(Enum):
    SHELL = 1

replace_token = '<FUNCTION_NAME>'

test_dict = {
    'libsodium': {
        'run': TestRunMode.SHELL,
        'modify': ModifyMode.INSERT_IN_LINE,
        'testsPath': 'test/default',
        'insertLine': 117,
        'insertString': f'exec {intel_pin_bin} -t {pintool} -- "$progdir/$program" ${{1+"$@"}} {replace_token}\n',
        'tests': {
            '0_sodium_is_zero': 'xchacha20',
            '1_sodium_bin2hex': 'xchacha20',
            '2__crypto_scalarmult_ed25519_is_inf': 'core_ed25519',
            '3__crypto_scalarmult_ed25519_clamp': 'core_ed25519',
            '4_sc25519_is_canonical': 'core_ed25519',
            }
        }
    }


def insert_in_line(file, line, replacement):
    try:
        lines = []
        with open(file, "r") as f:
            lines = f.readlines()
            lines[line-1] = replacement
        
        with open(file, "w") as f:
            f.writelines(lines)


    except:
        print(f'failed to open file {file}')


def run_shell_command(commandPath):
    outfile = f'{commandPath}.insts'
    sp = os.path.split(commandPath)
    try:
        with open(outfile, 'w+') as f:
            print(f'Running {commandPath}')
            subprocess.run(commandPath, cwd=sp[0], stdout=f)
    except:
        os.remove(outfile)
        print(f'failed to run {commandPath}')


def main():
    # walk the out dir
    for project_name in os.listdir(verification_output_dir):
        project = test_dict[project_name]
        to_test = []
        for fn in os.listdir(os.path.join(verification_output_dir, project_name)):
            for variant_result in os.listdir(os.path.join(verification_output_dir, project_name, fn)):
                with open(os.path.join(verification_output_dir, project_name, fn, variant_result), 'r') as f:
                    res = json.load(f)
                    print(variant_result)
                    verification_info = res.get('verification')
                    if verification_info == None:
                        continue
                    for key in verification_info.keys():
                        if verification_info[key]['correct transformations'] > 0:
                            to_test.append(res['shadow_folder'])
        

        for variant in to_test:
            fnname = variant.strip().split('/')[-1].split('-')[1]
            replacement = project['insertString'].replace(replace_token, fnname[2:]) #hack
            match project['modify']:
                case ModifyMode.INSERT_IN_LINE:
                    insert_in_line(
                        f'{variant}/{project["testsPath"]}/{project["tests"][fnname]}',
                        project['insertLine'],
                        replacement)
            match project['run']:
                case TestRunMode.SHELL:
                    run_shell_command(f'{variant}/{project["testsPath"]}/{project["tests"][fnname]}')

    return 0



if __name__ == '__main__':
    main()
