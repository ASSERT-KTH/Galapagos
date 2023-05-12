# import tabulate
import os
import sys
import pandas as pd
import tabulate

def main(args):
    workspace = os.path.abspath(os.path.join(os.path.dirname(__file__), '../rosetta_codes'))
    programs = ['lcs','md5','quicksort','sudoku']
    prompts = ['0','1']

    for prog in programs:
        for prompt in prompts:
            report = os.path.join(workspace, prog, f'compiled/report.p{prompt}.csv')
            print(report)
            pd.read_csv(report)
            
    return


    
if __name__ == "__main__":

    main(sys.argv)