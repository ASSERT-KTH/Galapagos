import (
    "os"
    "fmt"
)

func xwrite_stdout(buffer []byte, n_bytes uint64) {
    if n_bytes > 0 {
        n, err := os.Stdout.Write(buffer)
        if err != nil || uint64(n) < n_bytes {
            fmt.Fprintf(os.Stderr, "error writing %s: %v", "standard output", err)
            os.Exit(1)
        }
    }
}