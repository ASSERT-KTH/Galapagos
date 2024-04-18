import numpy as np
import matplotlib.pyplot as plt
import os
import pathlib

clones_dir = f'{os.environ["HOME"]}/galapagos-clones'

def getInstructions(file):
    addr_to_mnemonic = {}
    r = {}

    with open(f'{clones_dir}/{file}', 'r') as f:
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
    for p in pathlib.Path(clones_dir).rglob('*.insts'):
        relative = str(p.relative_to(clones_dir))
        print (relative)
        split_name = relative.split('-')
        library = split_name[0] 
        function = split_name[1] 
        

        if instfiles.get(library) == None:
            instfiles[library] = {}
        library_dict = instfiles[library]
        
        if library_dict.get(function) == None:
            library_dict[function] = []
        files = library_dict[function]

        files.append(relative)

    return instfiles
        
files = find_insts_files()


for project_key in files.keys():
    for test_key in files[project_key].keys():
        inst_data = []
        for file in files[project_key][test_key]:
            inst_data.append(getInstructions(file))
        

            all_insts = set([])
            for insts in inst_data:
                all_insts = all_insts.union(set(insts.keys()))

            all_insts = list(all_insts)
            all_insts.sort()

            print(inst_data)

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
            # plt.ylim(0, 5)

            # Plot each category
            for i, category_values in enumerate(values):
                ax.plot(angles, category_values, linewidth=1, linestyle='solid', label=f'Variant {i+1}')
                ax.fill(angles, category_values, alpha=0.1)

            plt.text(x=4.712, y=1e8, s=test_key, ha='center', va='center', fontsize=12, color='black')
            plt.subplots_adjust(bottom=0.2)
            plt.savefig(f'./plots/{test_key}-instruction_count.pdf', bbox_inches='tight')
