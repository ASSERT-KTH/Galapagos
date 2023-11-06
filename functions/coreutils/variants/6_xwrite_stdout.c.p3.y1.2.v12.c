import (
    "fmt"
    "os"
)

func xwrite_stdout(buffer string, n_bytes int) {
    if n_bytes > 0 {
        n, err := os.Stdout.WriteString(buffer[:n_bytes])
        if err != nil || n < n_bytes {
            fmt.Fprintf(os.Stderr, "error writing %v", "standard output")
            os.Exit(-1)
        }
    }
}