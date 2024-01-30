go
import (
    "os"
    "fmt"
    "syscall"
)

func xwrite_stdout(buffer []byte, n_bytes int) {
    if n_bytes > 0 {
        _, err := os.Stdout.Write(buffer[:n_bytes])
        if err != nil {
            fmt.Println("error writing standard output:", err.(*os.PathError).Err.Error())
            os.Exit(1)
        }
    }
}


Please note that this Go function doesn't fully replicate the behaviour of the C function as the Go functions provided by the standard library don't support setting errnos. 

Translated Function Signature:
In the Go language, strings are passed as byte slices([]byte) and size_t int type is appropriate to define buffer size.

External Library Dependency:
syscall - provides an inferface to low-level operating system primitives. (for obtaining error through the errno code)

Please Note: 
Handling Go's Error object is different than handling C's errno(which returns a numerical error). Go uses structured typed error where as C uses errno to get pointer for error descriptions.

Although not compulsory, almost all errors are some wrappers around os.PathError in I/O operations in Go. We try to cast our error object into this type to get more details (filename and error) in our message. 

Handling errno in Go most probably need some CGO calls or unsafe handling with wrapper libraries, generally a non recommended way.

Quoteaf doesn't exist in go, so quotes are hardcoded. 

Modified functionality because GO docs suggests os.Stdout.Write should not be expected to return error in case of partial write (https://pkg.go.dev/io#Writer). It may return err!=nil only if no byte has been written. Languages treat stdoit differently.