from generate_c import pipeline


if __name__ == '__main__':
    
    for opt in ["O0", "O1", "O2", "O3"]:
    
        hashes_source = set()
        hashes_target = set()
        hash_per_file = {

        }

        COUNT = 0
        
        for i in range(1, 39):
            f , hsh, hshsource = pipeline(f"rosetta_codes/quicksort.v{i}.c", opt)
            if hsh is not None:
                hashes_source.add(hshsource)
                
                hashes_target.add(hsh)
                
                if hsh not in hash_per_file:
                    hash_per_file[hsh] = []
                
                hash_per_file[hsh].append(f)

                COUNT += 1

        print(opt, len(hashes_source), len(hashes_target), f"{100*len(hashes_target)/COUNT}%", COUNT)

        for k, files in hash_per_file.items():
            if len(files) > 1:
                print(k)
                for f in files:
                    print(f"\t{f}")