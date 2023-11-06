It is not fully possible to make a semantically equivalent version of the given C function in Go due to several reasons. First, function pointers in Go do not behave the same way as in C, and second, Go doesn't allow void as a return type. That being said, we can closely approximate the function as below.

Assume that SodiumCritEnter, SodiumCritLeave and MisuseHandler are previously defined to correspond approximately to the C version's functionality.

go
func sodiumMisuse() {
    SodiumCritLeave()

    if SodiumCritEnter() == 0 {
        if MisuseHandler != nil {
            MisuseHandler()
        }
    }

    os.Exit(1)
}


In this Go function, the SodiumCritEnter and SodiumCritLeave functions correspond to the sodium_crit_enter and sodium_crit_leave C functions respectively. 

The MisuseHandler function variable corresponds to the _misuse_handler function pointer in the C code.

Finally C's abort() function is replaced with os.Exit(), a similar function in Go that kills the process.