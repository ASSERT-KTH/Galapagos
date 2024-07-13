from generate_variants import WORKSPACE
from split_variants_miscompilation import read_params

import json
from os import path

def type_to_params(types):
    r = []
    for t in types:
        if (t == 'int64' or t == 'int' or t == 'int*' or t == 'int16' 
            or t == 'int32' or t == 'uint64' or t == 'uint32' or t == 'uint'):
            r.append('0')
        if t == 'unsigned char':
            r.append('\'a\'')
        if t == 'uint64*':
            r.append('&a')
    return r

def read_variants(function_path):
    with open(path.join(function_path, 'functions_info.json')) as f:
        return json.loads(f.read())

def template_variants(variants, lang, function_path):
    with open(path.join(function_path, f'template.{lang}')) as template_file:
        template = template_file.read()
        #for each variant
        for i, v in enumerate(variants):
            for j in range(10):
                with open(path.join(function_path, 'variants', lang, f'{v["name"]}_{j}.{lang}.raw')) as variant_file:
                    text = variant_file.read()
                    replace_body = template.replace('<FUNCTION>', text)
                    
                    params = ','.join(type_to_params(v['params']))
                    fn_call = text.split('(')[0].split()[-1] 
                    fn_call = f'{fn_call}({params})'
                    replace_call = replace_body.replace('<FUNCTION CALL>', fn_call)

                    with open(path.join(function_path, 'variants', lang, f'{v["name"]}_{j}.{lang}'), 'w') as templated_file:
                        templated_file.write(replace_call)

lang, project = read_params()
function_path = path.join(WORKSPACE, 'miscompilation', project, 'function')
template_variants(read_variants(function_path), lang, function_path)
