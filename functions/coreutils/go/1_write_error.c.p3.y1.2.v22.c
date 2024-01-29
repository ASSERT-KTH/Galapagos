Unfortunately, it isn't possible to directly translate this C code to Go because Go does not have a direct analog to the error function in C; it does not support error handing at the same programmatic structure. However, here's an approximation on how you'd write this in Go.

go
import (
    "fmt"
    "os"
    "syscall"
)

func writeError() {
    err := syscall.GetErrno() 
    os.Stdout.Sync()

    _, writeErr := fmt.Fprintln(os.Stdout, "")
    if writeErr != nil {
        fmt.Fprintf(os.Stderr, "write error: %s\n", writeErr.Error())
        os.Exit(1)
    }

    if err != 0 {
        fmt.Fprintf(os.Stderr, "original error: %s\n", err.Error())
        os.Exit(1)
    }
}


In that solution:

- The function throwable is not invocable in Go. Software written in Go traditionally utilise the built-in `error` interface to handle errors.

- The call to os.Stdout.Sync to flush stdout buffer. 

- Any statement regarding 'errno'--a variable traditionally used in Unix system calls to show error status--is not directly communicated in Go. Instead of it, the GetErrno() method is used from sys package for reproducing errno.

- It evaluates an attempt to transcribe an error message to stdout and replicate the output and halt behaviour of error function.  

Please note that idiomatic Go usually does not involve calling os.Exit; instead, you'd return an error from this function and let the caller decide whether to exit. However, this version preserves the exit-on-failure behaviour of the input C code for symmetry.