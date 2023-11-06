import (
    "fmt"
    "os"
)

func xwrite_stdout(buffer string, n_bytes int) {
    if n_bytes > 0 {
        nbytes, err := fmt.Fprint(os.Stdout, buffer[:n_bytes])
        if err != nil || nbytes < n_bytes {
            fmt.Fprintln(os.Stderr, "error writing standard output")
            os.Exit(1)
        }
    }
}