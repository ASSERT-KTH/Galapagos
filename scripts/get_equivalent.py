import subprocess
import json

outfiles_dir = '/home/javier/Galapagos/scripts/out'

def get_outfiles():
    files = subprocess.check_output(['grep', '-l', '-r', '"correct transformations": 1', outfiles_dir], text=True).strip().split('\n')
    return files


def get_project_variant_lang_number(outfiles):
    r = []
    for outfile in outfiles:
        with open(outfile, 'r') as f:
            obj = json.load(f)
            all_info_str = obj['changes']['bitcodes'][0][1]
            idx = all_info_str.find('galapagos-clones')
            all_info = all_info_str[idx:].split('/')[1]
            specs = all_info.split('-')
            project = specs[0]
            if project == 'alsa':
                project = 'alsa-lib'
                function = specs[2][2:]
                if len(specs) == 5:
                    lang = specs[4]
                    number = specs[3]
                elif len(specs) == 4:
                    lang = 'go' # hack
                    number = specs[3]
                r.append((project, function, lang, number))
            else:
                function = specs[1][2:]
                lang = specs[3]
                number = specs[2]
                r.append((project, function, lang, number))
    return r



def to_json(eq_tuples):
    r = {}
    for (project, function, lang, n) in eq_tuples:
        if project not in r:
            r[project] = {}
        if function not in r[project]:
            r[project][function] = {'c':[], 'go': []}
        
        r[project][function][lang].append(n)
    
    return json.dumps(r, indent=4)

outfiles = get_outfiles()
x = get_project_variant_lang_number(outfiles)
x = to_json(x)
print(x)
