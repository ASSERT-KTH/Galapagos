The original C code uses the 'dlsym' function which is used to get the address of a specified symbol (function, data object, etc.) in a shared library. It's also delayed by calling `select`. 

In Go, we don't have access to such APIs because Go statically links all imported packages. So, it is not possible to make a symbol lookup inside the currently running program. Same goes for delay, Go uses blocking instead of polling involving system select call. However, the nearest Go equivalent is by using a sleep for the `select` and by directly calling `os.Exit`.

Here's a possible implementation given these constraints:

go
import (
    "os"
    "time"
)

func exit(status int) {
    time.Sleep(100 * time.Millisecond)
    os.Exit(status)
}


This code simulates a delay similar to what `select` did in the C code with `time.Sleep()`, and instead of searching dynamically for the `exit` symbol, simply calls the `os.Exit()` function directly, because that symbol is statically linked at compile time. It is unable to use any form of 'RTLD_NEXT' or 'dlsym' equivalent as Go doesn't support this. These are limitations due to the way go programs are compiled and linked together. Each package imported is compiled down into the binary, and accessing dynamic symbols from the running program isn't supported.