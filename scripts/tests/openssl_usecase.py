
import asyncio
import usecases.openssl
from usecases.case import is_executable
import verifier
import logging

if __name__ == "__main__":
    # Compile openssl
    import sys    
    logging.basicConfig(level=logging.DEBUG)
    uc = usecases.openssl.OpenSSL()

    verif = verifier.AliveVerifier(debug=True)

    async def comp1(src):
        shadow = await uc.shadow(src, name="opensslt1")
        await uc.compile(shadow, uc.initial_source_code)

        return shadow

    async def comp2(src):
        shadow = await uc.shadow(src, name="opensslt2")
        await uc.compile(shadow, uc.changed_source_code)
        return shadow


    async def mm():
        shadow1 = asyncio.create_task(comp1(sys.argv[1]))

        shadow1 = await shadow1

        # TODO we can call this function as "clone" instead of shadow
        print("Compiling variant code")
        try:

            shadow2 = asyncio.create_task(comp2(sys.argv[1]))
            shadow2 = await shadow2

            modified, in1, in2 = await uc.compare_shadows(shadow1, shadow2)
            # There should not be new or removed files
            assert len(in1) == 0, "The new compilation removes files. That is not possible"
            assert len(in2) == 0,  "The new compilation adds new files. That is not possible"

            # Now we filter those that are, binaries, bitcodes or source code
            print("Modified files", len(modified))
            
            bitcodes = [ (f1, f2) for f1, f2 in modified if f1.endswith(".bc") and f2.endswith(".bc") ]
            executables = [ (f1, f2) for f1, f2 in modified if is_executable(f1) and is_executable(f2) ]
            source_code = [(f1, f2) for f1, f2 in modified if (f1.endswith(".c") or f1.endswith(".cpp")) and (f2.endswith(".c") or f2.endswith(".cpp"))]

            assert len(source_code) > 0, "There are not changed source codes"

            print("Bitcodes", len(bitcodes), bitcodes)
            print("Executables", len(executables), executables)

            if len(bitcodes) == 0:
                print("Warning there are not changed bitcodes. Either you are not changing the source code or the transormation is not preserved")
                # TODO report non preserved
            else:
                # Check if there is at least one changed binary, otherwise the transformation is not preserved
                if len(executables) == 0:
                    print("No binary changed, meaning that probably no transformation is preserved")
                else:
                    # Do the verification of the bitcodes
                    print("Doing verification")
                    for f1, f2 in bitcodes:
                        print("Verifying ", f1, f2)
                        r1 = await verif.async_verify(open(f1, 'r'), open(f2, 'r'), entrypoint="bn_free_d", timeout=300_000)



            print(modified)
        except Exception as e:
            print("Project could not compile", e)


    asyncio.run(mm())

    # change source code
    # compile again
    # verify changed Bitcodes

