from generate_c import pipeline, WORKSPACE
import os
import time

if __name__ == '__main__':
    open(os.path.join(WORKSPACE, f"rosetta_codes/compiled/report.csv"), 'w').close()
    for epoch in range(1, 100):
        filessc = os.listdir(os.path.join(WORKSPACE, "rosetta_codes"))
        for opt in ["O0", "O1", "O2", "O3", "Os", "Ofast"] :
        
            hashes_source = set()
            hashes_target = set()
            hash_per_file = {

            }

            hash_per_filesc = {

            }
            COUNT = 0
            
            for f in filessc:
                if ".v" in f:
                    filepath = os.path.join(WORKSPACE, "rosetta_codes", f)
                    f , hsh, hshsource = pipeline(filepath, opt)
                    if hsh is not None:
                        hashes_source.add(hshsource)
                        
                        hashes_target.add(hsh)
                        
                        if hsh not in hash_per_file:
                            hash_per_file[hsh] = []
                        
                        hash_per_file[hsh].append(f)

                        if hshsource not in hash_per_filesc:
                            hash_per_filesc[hshsource] = []
                        
                        hash_per_filesc[hshsource].append(f)

                        COUNT += 1

            reportfile = open(os.path.join(WORKSPACE, f"rosetta_codes/compiled/report.csv"), 'a')
            reportfile.write(f"{epoch},{opt},{len(hashes_source)},{len(hashes_target)}, {COUNT}, {100*len(hashes_target)/COUNT},{len(filessc)}%\n")

            print(opt, len(hashes_source), len(hashes_target), f"{100*len(hashes_target)/COUNT}%", COUNT)

            print("MC")
            for k, files in hash_per_file.items():
                if len(files) > 1:
                    print(k)
                    for f in files:
                        print(f"\t{f}")
            
            print("SC")
            for k, files in hash_per_filesc.items():
                if len(files) > 1:
                    print(k)
                    for f in files:
                        print(f"\t{f}")

        time.sleep(60)