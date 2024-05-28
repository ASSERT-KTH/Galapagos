from generate_variants import WORKSPACE
import json
from os import path

lang = 'go'
function_path = path.join(WORKSPACE, 'functions', 'liboqs')

def type_to_params(types):
    r = []
    for t in types:
        if t == 'int64':
            r.append('0')
    return r

def read_variants():
    with open(path.join(function_path, 'functions_info.json')) as f:
        return json.loads(f.read())

def template_variants(variants):
    with open(path.join(WORKSPACE, 'functions', f'template.{lang}')) as template_file:
        template = template_file.read()
        #for each variant
        for i, v in enumerate(variants):
            for j in range(10):
                with open(path.join(function_path, 'variants', lang, f'{i}_{v["name"]}_{j}.{lang}.raw')) as variant_file:
                    text = variant_file.read()
                    replace_body = template.replace('<FUNCTION>', text)
                    
                    params = ','.join(type_to_params(v['params']))
                    fn_call = f'{v["name"]}({params})'
                    replace_call = replace_body.replace('<FUNCTION CALL>', fn_call)

                    with open(path.join(function_path, 'variants', lang, f'{i}_{v["name"]}_{j}.{lang}'), 'w') as templated_file:
                        templated_file.write(replace_call)


template_variants(read_variants())
