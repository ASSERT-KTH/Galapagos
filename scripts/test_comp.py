from generate_c import llvm_pipeline, WORKSPACE
import os
import time
import verifier
import logging

if __name__ == '__main__':
    logging.basicConfig(level=logging.DEBUG)
    # Do the pipeline with the original

    # for epoch in range(1, 2):
    filessc = os.listdir(os.path.join(WORKSPACE, "rosetta_codes", "md5"))
    filessc = [ f for f in filessc if ".v" in f ] + [ "md5.c" ] # Adding the original as well
    original_llvm = None

    alive_verifier = verifier.AliveVerifier(debug=True)

    reportfile = open(os.path.join(WORKSPACE, f"rosetta_codes/compiled/report.csv"), 'w')
    reportfile.write("Total files, Opt level, Unique SC, Unique MC, Compiled, Unique SC%, Unique MC%, SVerified count\n")

    reportfile_verification = open(os.path.join(WORKSPACE, f"rosetta_codes/compiled/verification.csv"), 'w')
    reportfile_verification.write("File, Verified\n")

    for opt in ["O0", "O1", "O2", "O3", "Os", "Ofast"] :
    
        hashes_source = set()
        hashes_target = set()
        hash_per_file = {

        }

        hash_per_filesc = {

        }
        COUNT = 0
        SUCCESS_VERIFICATION = 0
        
        for f in filessc:
            filepath = os.path.join(WORKSPACE, "rosetta_codes", "md5", f)
            f , hsh, hshsource, llvm_ir_filename = llvm_pipeline(filepath, opt, generate_llvm_ir=True)
            
            equivalent = False
            if original_llvm is None and ".v" not in f:
                original_llvm = llvm_ir_filename
            
            elif original_llvm and llvm_ir_filename:
                # Do the verification here :|
                f1 = open(original_llvm, 'r')
                f2 = open(llvm_ir_filename, 'r')
                verification_result = alive_verifier.verify(f1, f2)

                print(f"Verified {verification_result}")
                if verification_result and verification_result.is_ok():
                    SUCCESS_VERIFICATION += 1
                    equivalent = True

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

            reportfile_verification = open(os.path.join(WORKSPACE, f"rosetta_codes/compiled/verification.csv"), 'a')
            reportfile_verification.write(f"{f}, {equivalent}\n")

        reportfile = open(os.path.join(WORKSPACE, f"rosetta_codes/compiled/report.csv"), 'a')
        reportfile.write(f"{len(filessc)}, {opt},{len(hashes_source)},{len(hashes_target)}, {COUNT}, {100*len(hashes_target)/COUNT}%, {100*len(filessc)/COUNT}%, {SUCCESS_VERIFICATION}\n")

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

        # time.sleep(60/len(filessc))