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
        'alaw_to_s16-c',
        'montgomery_reduce-c',
        'int16_nonzero_mask-c',
        'alaw_to_s16-go',
        'mix-go',
        'montgomery_reduce-go',
        'int16_nonzero_mask-go',
        'icbrt64-go',
        'alaw_to_s16-original',
        'mix-original',
        'montgomery_reduce-original',
        'int16_nonzero_mask-original',
        'fBlaMka-original',
        'icbrt64-original',
        'fBlaMka-c',
        'icbrt64-c',
        'mix-c']
    paths = [ f'/home/javier/Galapagos/scripts/dynamic/{p}' for p in paths]
    for p in paths:
        split_name = str(p).split('/')[-1].split('-')
        fn = split_name[0] 

        if not fn in instfiles:
            instfiles[fn] = []
        instfiles[fn].append(str(p))
        
    for fn in instfiles:
        instfiles[fn] = sorted(instfiles[fn])
    return instfiles
        
files = find_insts_files()

def get_label(fn, i):
    if fn == 'fBlaMka':
        return ['c','original'][i]
    return ['c', 'go', 'original'][i]

def get_inst_order(fn):
    return {
        'alaw_to_s16': ['movzx', 'add', 'sub', 'jnl', 'cmp', 'shl', 'ret', 'push', 'pop', 'mov', 'jz', 'xor', 'and', 'sar', 'test', 'sbb', 'neg', 'lea', 'jl', 'dec', 'data16', 'jle', 'jmp', 'or' ],
        'fBlaMka': ['add', 'and', 'imul', 'mov', 'pop', 'push', 'ret', 'shl'],
        'icbrt64': [ 'ret', 'add', 'cmp', 'imul', 'jl', 'jmp', 'mov', 'shr', 'shl', 'sub', 'jb', 'pop', 'push', 'jnbe', 'lea', 'nop', 'test', 'xor'],
        'int16_nonzero_mask':['ret', 'add', 'movzx', 'shr', 'sub', 'pop', 'push', 'xor', 'mov', 'cmovnz', 'cmp', 'movsx', 'jnz', 'test'],
        'mix': ['add', 'cdq', 'idiv', 'pop', 'push', 'ret', 'and', 'mov', 'sar', 'shl', 'imul', 'lea', 'movsxd', 'sub'],
        'montgomery_reduce': ['cwde', 'mov', 'pop', 'push', 'imul', 'movsx', 'ret', 'sar', 'sub', 'xor']
    }[fn]

for fn in files.keys():
    inst_data = []
    for file in files[fn]:
        inst_data.append(getInstructions(file))
    
        all_insts = set([])
        for insts in inst_data:
            all_insts = all_insts.union(set(insts.keys()))

        all_insts = list(all_insts)
        all_insts.sort()

        all_insts = get_inst_order(fn)
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
