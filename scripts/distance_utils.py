import re

ABSOLUTE_ADDRESS_RE = r'^[0-9a-f]+: (([0-9a-f]){2} )+[ ]+'
ABSOLUTE_FUNC_ADDRE = r'(0x)?[0-9a-f]+ <'
ABSOLUTE_FUN_NAME = r'<.+?>'
# ABSOLUTE_JMP_RE = re.compile()

def clean_code(content, remove_function_name=True):
    # do line by line
    lines = content.split('\n')

    result = ""
    for l in lines[2:]:
        # Remove absolute address in the start of the line
        r = re.sub(ABSOLUTE_ADDRESS_RE, '', l)
        r = re.sub(ABSOLUTE_FUNC_ADDRE, '<', r)
        if remove_function_name:
            r = re.sub(ABSOLUTE_FUN_NAME, '<>', r)
        # print(r)
        result += r + "\n"

    return result




if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument("file", type=str, help="File to read")
    args = parser.parse_args()
    
    content = open(args.file, 'r').read()
    result = clean_code(content)

    print(result)
