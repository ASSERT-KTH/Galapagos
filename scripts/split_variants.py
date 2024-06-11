
from os import path
import sys
from generate_variants import WORKSPACE
import json


def read_variants(function_path):
    with open(path.join(function_path, 'functions_info.json')) as f:
        return json.loads(f.read())

def split(info, function_path, lang):
    for i, fn in enumerate(info):
        with open(path.join(function_path, 'variants', lang, f'{i}_{fn["name"]}.c.variants')) as fn_file:
            data = fn_file.read()
            
            start = 0
            if lang == 'go':
                start = data.find('func')
            elif lang == 'c':
                start = data.find(fn['return'])
            it = 0
            while start != -1:
                iter = start
                count = 1
                end = data.find('{', iter)
                while count > 0:
                    end += 1
                    if data[end] == '{':
                        count += 1
                    if data[end] == '}':
                        count -= 1
                with open(path.join(function_path, 'variants', lang, f'{i}_{fn["name"]}_{it}.{lang}.raw'), 'w') as out:
                    out.write(data[start:end+1])
                    out.write('\n')
                if lang == 'go':
                    start = data.find('func', end)
                elif lang == 'c':
                    start = data.find(fn['return'], end)
                it += 1
                if it > 20:
                    exit(-1)


def read_params():
    params = sys.argv[1:]
    lang = params[0]
    project = params[1]
    return lang, project

lang, project = read_params()
function_path = path.join(WORKSPACE, 'functions', project)
split(read_variants(function_path), function_path, lang)
        
