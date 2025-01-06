import subprocess
import json
from generate_variants import WORKSPACE
from split_variants import read_params
import os
import os.path as path


def get_instruction_set(file):
    inst_map = {}
    inst_count = {}
    with open(file, 'r') as f:
        data = f.readlines()
        for line in data:
            tokens = line.strip().split(' ')
            if len(tokens) > 1:
                if tokens[1] not in inst_count:
                    inst_count[tokens[1]] = 0
                inst_count[tokens[1]] += 1
                inst_map[tokens[0]] = tokens[1]
            else:
                inst_count[inst_map[tokens[0]]] += 1
    return inst_count

def read_variants(function_path):
    with open(path.join(function_path, 'functions_info.json')) as f:
        return json.loads(f.read())

def process(variants, lang, function_path):
    report = {}    
    with open('eq_variants.json', 'r') as eq_file:
        eq = json.load(eq_file)
    
    #for each variant
    for i, v in enumerate(variants):
        if not v['name'] in eq[project]:
            continue
        report[v['name']] = {}
        execution = path.join(exec_path, f'{v["name"]}')
        original_count = get_instruction_set(execution)
        original_set = set(original_count.keys())
        for lang in ['c', 'go']:
            function_lang_count = 0
            function_lang_avg = 0
            for j in eq[project][v['name']][lang]:
                execution = path.join(exec_path, f'{v["name"]}-{j}-{lang}')
                try:
                    variant_count = get_instruction_set(execution)
                except:
                    continue
                variant_set = set(variant_count.keys())
                # print(v['name'], variant_set)
                overlap = len(variant_set.intersection(original_set))
                total_instructions = len(variant_set.union(original_set))
                overlap_percentage = overlap / total_instructions
                print(v['name'], j, lang, overlap_percentage)
                function_lang_avg += overlap_percentage
                function_lang_count += 1
            if function_lang_count == 0:
                continue
            function_lang_avg /= function_lang_count
            
            report[v['name']][lang] = function_lang_avg

    glob = {}
    for lang in ['c','go']:
        lang_avg = 0
        lang_count = 0
        for fn in report:
            if lang in report[fn]:
                lang_avg += report[fn][lang]
                lang_count += 1
        if lang_count == 0:
            continue
        lang_avg /= lang_count
        glob[f'total_{lang}'] = lang_avg 
    report['global'] = glob
            


    with open(f'{exec_path}/{project}-overlap.json', 'w+') as ov:
        json.dump(report, ov, indent=4) 

lang, project = read_params()

function_path = path.join(WORKSPACE, 'functions', project)
exec_path = '/home/javier/Galapagos/scripts/dynamic'

process(read_variants(function_path), lang, function_path)


