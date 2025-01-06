import numpy as np
import matplotlib.pyplot as plt
import os
import pathlib

insts_dir = f'{os.environ["HOME"]}/Galapagos/scripts/dynamic'

def getInstructions(file):
    addr_to_mnemonic = {}
    r = {}

    with open(file, 'r') as f:
        lines = f.readlines()
        for line in lines:
            split_line = line.strip().split(' ')
            if len(split_line) > 1:
                addr_to_mnemonic[split_line[0]] = split_line[1]
            else:
                i = addr_to_mnemonic[split_line[0]]
                if r.get(i) == None:
                    r[i]= 0
                r[i] += 1
    return r

def find_insts_files():
    instfiles = {}
    paths = [
        'alaw_to_s16-original',
        'alaw_to_s16-1-c',
        'alaw_to_s16-7-go',
        'iec958_parity-original',
        'iec958_parity-2-c',
        'iec958_parity-2-go',
#        'ulaw_to_s16-original',
#        'ulaw_to_s16-5-c',
#        'ulaw_to_s16-1-go',
        'ctz-original',
        'ctz-1-c',
        'ctz-0-go',
        'int16_t_negative_mask-original',
        'int16_t_negative_mask-0-c',
        'int16_t_negative_mask-1-go',
        'int16_t_nonzero_mask-original',
        'int16_t_nonzero_mask-0-c',
        'int16_t_nonzero_mask-9-go',
#       'montgomery_reduce-original',
#       'montgomery_reduce-c',
#       'montgomery_reduce-go',
#       'fpr_half-original',
#       'fpr_half-c',
#       'fpr_half-go',
#       'int16_nonzero_mask-original',
#       'int16_nonzero_mask-c',
#       'int16_nonzero_mask-go',
        '_booth_recode_w5-original',
        '_booth_recode_w5-0-c',
        '_booth_recode_w5-0-go'
        ]
    paths = [ f'/home/javier/Galapagos/scripts/dynamic/{p}' for p in paths]
    for p in paths:
        split_name = str(p).split('/')[-1].split('-')
        fn = split_name[0] 

        if not fn in instfiles:
            instfiles[fn] = []
        instfiles[fn].append(str(p))
        
    for fn in instfiles:
        instfiles[fn] = instfiles[fn]
    return instfiles
        
files = find_insts_files()

def get_label(fn, i):
    if fn == 'fBlaMka':
        return ['original', 'c'][i]
    return ['original','c', 'go'][i]

def get_inst_order(fn):
    return {
        'alaw_to_s16': [
 'movzx',
 'sub',
 'add',
 'and',
 'cmp',
 'jz',
 'mov',
 'xor',
 'shl',
 'jmp',
 'cdq',
 'idiv',
 'jnbe',
 'test',
 'setnz',
 'jnz',
 'setl',
 'ret',
 'or',
 'pop',
 'push',
 'sar',
 'jle',
 'jnl',],
    'icbrt64': [
 'mov',
 'sub',
 'add',
 'cmp',
 'imul',
 'jmp',
 'shl',
 'shr',
 'and',
 'test',
 'setl',
 'setnb',
 'jnbe',
 'jnz',
 'jz',
 'setnl',
 'pop',
 'jb',
 'jl',
 'push',
 'ret',
],
    'montgomery_reduce': [
 'sub',
 'sar',
 'mov',
 'imul',
 'add',
 'cmp',
 'jnbe',
 'cwde',
 'pop',
 'push',
 'xor',
 'movsx',
 'ret',
],
    'int16_nonzero_mask': [
 'sub',
 'add',
 'mov',
 'and',
 'cmp',
 'movsx',
 'ret',
 'jmp',
 'jnbe',
 'jz',
 'test',
 'setnz',
 'imul',
 'pop',
 'push',
 'movzx',
 'shr',
 'xor',
],
    'mix': ['add',
 'and',
 'cdq',
 'shl',
 'mov',
 'idiv',
 'sar',
 'ret',
 'cmp',
 'jmp',
 'jnbe',
 'jnz',
 'sub',
 'test',
 'xor',
 'pop',
 'push',
],
    'fBlaMka': None,
    }.get(fn)

for fn in files.keys():
    inst_data = []
    for file in files[fn]:
        inst_data.append(getInstructions(file))
    
        all_insts = set([])
        for insts in inst_data:
            all_insts = all_insts.union(set(insts.keys()))

        all_insts = list(all_insts)
        all_insts.sort()
        
        print(file.split('/')[-1], all_insts)

        order = get_inst_order(fn)
        if order != None:
            all_insts = order
        # Number of attributes
        num_attributes = len(all_insts)

        # Compute angle for each axis
        angles = np.linspace(0, 2 * np.pi, num_attributes, endpoint=False).tolist()

        # Make the plot close to a circle
        values = []
        for category_data in inst_data:
            category_values = []
            for attr in all_insts:
                v = category_data.get(attr)
                if v == None:
                    category_values.append(0)
                else:
                    category_values.append(v)
            category_values.append(category_values[0])  # Close the loop
            values.append(category_values)
        angles += angles[:1]

        # Plot
        fig, ax = plt.subplots(figsize=(4, 4), subplot_kw=dict(polar=True))

        # Draw one axe per variable and add labels
        plt.xticks(angles[:-1], all_insts, color='grey', size=10)

        # Draw ylabels
        ax.set_rscale('symlog')
        plt.yticks(color="grey", size=8)
        plt.ylim(0, 500)

        # Plot each category
        for i, category_values in enumerate(values):
            ax.plot(angles, category_values, linewidth=1, linestyle='solid', label=get_label(fn, i))
            ax.fill(angles, category_values, alpha=0.1)
            ax.legend(loc=2, bbox_to_anchor=(-0.35, 1.125))
        
        plt.text(x=4.712, y=6000, s=fn, ha='center', va='center', fontsize=12, color='black')
        plt.subplots_adjust(bottom=0.2)
        plt.savefig(f'./plots/{fn}-instruction_count.pdf', bbox_inches='tight')
