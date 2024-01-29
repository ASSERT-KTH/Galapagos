Unfortunately, it's impractical to provide a direct one-to-one translation of this C code to Go. C's errno global variable used often for error handling at system calls does not perfectly map to any feature in Go. Moreover, Go's built-in packages like "os" and "errors" handle errors distinctly. Here's an idiomatic Go approximation of the C function:

go
import (
    "errors"
    "os"
)

func writeError() error {
    file := os.Stdout
    err := file.Sync() // Ensures nothing buffered that might induce an error.

    if err != nil {
        return errors.New("write error")
    }
    
    err := file.Close() // To avoid extraneous diagnostic from file.Close().

    if err != nil {
        return errors.New("write error")
    }
    
    return nil
}

In this scenario, function `writeError` detects a write error of the standard output stream and returns an instance of type error if there's an error. Please note, Go promotes idiomatic error handling by always returning an error, unlike C which often manipulates error states utilising global variables like errno. 

Functionally, it ensures the os.Stdout is synced with the disk (which is a close equivalent to `fflush(stdout)` in C library) and the output stream is closed without any problems (`close_stdout` in C). Both error cases return a "write error" similar to the original C version.