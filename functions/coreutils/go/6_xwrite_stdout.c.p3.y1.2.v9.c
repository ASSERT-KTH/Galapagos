Go is a strongly typed language, it is not possible to follow the function signature in Go. However, assuming the buffer that is inputted is of string type, the following might be a relevant implementation.

go
import (
    "fmt"
    "os"
)

func xwrite_stdout(buffer string, n_bytes uint) {
    if n_bytes > 0 {
        n, err := fmt.Printf("%s", buffer[:n_bytes])
        if err != nil || uint(n) < n_bytes {
            fmt.Fprintf(os.Stderr, "error writing: %s\n", "standard output")
            os.Exit(1)
        }
    }
}
