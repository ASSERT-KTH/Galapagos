import json
import glob
import pprint
import json2latex

def find_number_of_compiled(files):
    compiled = 0
    for f in files:
        if f['compiled'] == True:
            compiled += 1
    return compiled

def find_number_of_tested(files):
    tested = 0
    for f in files:
        if 'pass_tests' in f and f['pass_tests'] == True:
            tested += 1
    return tested


def find_number_of_equivalent(files):
    equivalent = 0
    for f in files:
        if 'verification' in f:
            bc_files = f['verification']
            for bc_file in bc_files:
                if bc_files[bc_file]['correct transformations'] > 0:
                    equivalent += 1
                    break
    return equivalent

projects = ['alsa-lib', 'ffmpeg', 'libsodium', 'openssl']
langs = ['c', 'go']

result = {}

for project in projects:
    result[project] = {}

    #load functions
    with open(f'../functions/{project}/functions_info.json') as f:
        data = json.load(f)
        for i, fn in enumerate(data):
            result[project][fn['name']] = {}
            # get .bc files path
            for lang in langs:
                result[project][fn['name']][lang] = {}

                path = f'../functions/{project}/variants/{lang}/{i}_{fn["name"]}*.bc'
                files = glob.glob(path)
                compile_in_isolation = len(files)
                result[project][fn['name']][lang]['compile_isolation'] = compile_in_isolation

                # compiles in project / pass tests / validates
                
                # open json files
                out_path = f'out/{project}/{lang}/{i}_{fn["name"]}/{i}_{fn["name"]}*.json'
                # print(out_path)
                out_files = glob.glob(out_path)
                out_jsons = []
                for out_file in out_files:
                    with open(out_file) as g:
                        out_jsons.append(json.load(g))
                compile_in_project = find_number_of_compiled(out_jsons)
                result[project][fn['name']][lang]['compile_project'] = compile_in_project

                pass_tests = find_number_of_tested(out_jsons)
                result[project][fn['name']][lang]['pass_tests'] = pass_tests
                
                equivalent = find_number_of_equivalent(out_jsons)
                result[project][fn['name']][lang]['equivalent'] = equivalent

def data_to_latex(result):
    s = ''
    for proj in result:
        s += '\\midrule\n'
        for i, func in enumerate(result[proj]):
            if i == 4:
                s += f'\\cellcolor{{white}}\n\\multirow{{-5}}{{*}}{{{proj}}} & {func} '
            else:
                s += f'\\cellcolor{{white}} & {func} '
            for lang in result[proj][func]:
                for point in result[proj][func][lang]:
                    s += f'& \\numprint{{{result[proj][func][lang][point]}}} '
            s += " \\\\\n"
    
    return s.replace('_', '\\_')

pprint.pprint(result)
print(data_to_latex(result))

