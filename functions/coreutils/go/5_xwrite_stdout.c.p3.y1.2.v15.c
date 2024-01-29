The equivalent code for the given C function, using the Go programming language would look something like this:

go
import (
    "fmt"
    "os"
)

func xwrite_stdout(buffer []byte, n_bytes int) {
    if n_bytes > 0 {
        _, err := os.Stdout.Write(buffer[:n_bytes])
        if err != nil {
            fmt.Printf("error writing %s: %s", "standard output", err)
            os.Exit(1)
        }
    }
}

Note: Go does not throw an explicit error if the number of bytes written is less than expected. That's why there is no equivalent check for `fwrite (buffer, 1, n_bytes, stdout) < n_bytes` in the Go code, which is done in the C version. Moreover, translation of some C-specific parts like `quoteaf`, error handling through `errno`, or equivalent, are excluded due to different working of Go for such pieces.