from generate_c import llvm_pipeline, WORKSPACE
import os
import time
import verifier
import logging

if __name__ == '__main__':
    logger = logging.getLogger("root")
    logger.setLevel(logging.DEBUG)

    # create console handler with a higher log level
    ch = logging.StreamHandler()
    ch.setLevel(logging.DEBUG)

    ch.setFormatter(verifier.CustomFormatter())

    logger.addHandler(ch)
    logging = logger
    # Do the pipeline with the original
    # TODO: separate each file

    # for epoch in range(1, 2):
    filessc = os.listdir(os.path.join(WORKSPACE, "rosetta_codes", "quicksort"))
    filessc = [ "quicksort.c" ] + [ f for f in filessc if ".v" in f ] # Adding the original as well in the first position
    original_llvm = {}

    alive_verifier = verifier.AliveVerifier(debug=True)

    reportfile = open(os.path.join(WORKSPACE, f"rosetta_codes/compiled/report.csv"), 'w')
    reportfile.write("Total files, Opt level, Unique SC, Unique MC, Compiled, Unique MC%, Unique SC%, SVerified count\n")

    reportfile_verification = open(os.path.join(WORKSPACE, f"rosetta_codes/compiled/verification.csv"), 'w')
    # reportfile_verification.write("File, VS, Opt, Verified\n")
    original_llvm = None
    original_hash = None

    for opt in ["O0", "O1", "O2", "O3", "Os", "Ofast"] :

        hashes_source = set()
        hashes_target = set()
        hash_per_file = {

        }

        hash_per_filesc = {

        }
        COUNT = 0
        SUCCESS_VERIFICATION = 0
        
        fixed_opt = "O0"
        for f in filessc:
            filepath = os.path.join(WORKSPACE, "rosetta_codes", "quicksort", f)
            f , hsh, hshsource, llvm_ir_filename = llvm_pipeline(filepath, opt, generate_llvm_ir=True)
            

            equivalent = False
            if hsh is not None:

                print(original_llvm)

                # Notice ! we always compare the original vs the variant in the same optimization level
                if original_llvm is None and ".v" not in f:
                    original_llvm = llvm_ir_filename
                    original_hash = hsh
                elif original_llvm and llvm_ir_filename:
                    # Do the verification here :|
                    f1 = open(original_llvm, 'r')
                    f2 = open(llvm_ir_filename, 'r')
                    verification_result = alive_verifier.verify(f1, f2, entrypoint="quicksort", timeout=60000, alive_flags=[
                        "--disable-undef-input",
                        "--disable-poison-input",
                        "--always-verify"
                    ])

                    print(f"Verified {verification_result}")
                    if verification_result:
                        if verification_result.is_ok():
                            SUCCESS_VERIFICATION += 1
                            equivalent = True
                            if hsh in hashes_source:
                                logging.warning(f"It is equivalent but it might be the same binary as the original {f}")
                        else:
                            logging.warning(f"Verification failed for {f}. {verification_result.error}")

                hashes_source.add(hshsource)
                
                hashes_target.add(hsh)
                
                if hsh not in hash_per_file:
                    hash_per_file[hsh] = []
                
                hash_per_file[hsh].append(f)

                if hshsource not in hash_per_filesc:
                    hash_per_filesc[hshsource] = []
                
                hash_per_filesc[hshsource].append(f)

                COUNT += 1

            if ".v" in f:
                reportfile_verification = open(os.path.join(WORKSPACE, f"rosetta_codes/compiled/verification.csv"), 'a')
                reportfile_verification.write(f"{f}, {original_llvm}, {hsh}, {original_hash}, {opt},{equivalent}\n")

        reportfile = open(os.path.join(WORKSPACE, f"rosetta_codes/compiled/report.csv"), 'a')
        reportfile.write(f"{len(filessc)}, {opt},{len(hashes_source)},{len(hashes_target)}, {COUNT}, {100*len(hashes_target)/COUNT}, {100*len(hash_per_filesc)/COUNT}, {SUCCESS_VERIFICATION}\n")

        print(opt, len(hashes_source), len(hashes_target), f"{100*len(hashes_target)/COUNT}%", COUNT, SUCCESS_VERIFICATION)

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
        # Saving file hashes
        import json
        with open(os.path.join(WORKSPACE, f"rosetta_codes/compiled/sc_hashes.json"), "w") as f:
            json.dump( hash_per_filesc, f, indent=4)

        with open(os.path.join(WORKSPACE, f"rosetta_codes/compiled/mc_hashes.json"), "w") as f:
            json.dump(hash_per_file, f, indent=4)

        # time.sleep(60/len(filessc))