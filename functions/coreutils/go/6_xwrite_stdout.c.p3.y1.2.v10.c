Unfortunately, it is not possible to change the function signature and translate the given C code exactly into the Go programming language as Go does not support explicit exception handling like C.

The error methods such as `errno`, `clearerr` and `exit` calls from C do not exist in Go. However, here's an equivalent approach in Go by writing bytes to stdout and dealing with potential error:

go
import (
    "fmt"
    "os"
)

func xwrite_stdout(buffer string, n_bytes int) error {
    if n_bytes > 0 {
        n, err := os.Stdout.Write([]byte(buffer[0:n_bytes]))
        if err != nil || n < n_bytes {
            return fmt.Errorf("error writing %s: %v", "standard output", err)
        }
    }
  
    return nil
}


The code tries to write the data to standard output - if it encounters an error (or the number of bytes written is less than `n_bytes`), it captures this information and returns it to the caller. This equivalent Go function conforms to conventional Go error handling.

Please note this Go version replaces the process-wide exiting of the C code, with a `return error`. In Go, error handling is done deliberately following the notion that `Errors are just values`, therefore explicitly do return with the erroneous condition rather than causing the entire process to fail since it may retain additional behavior for recovery.