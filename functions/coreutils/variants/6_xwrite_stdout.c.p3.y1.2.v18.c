import (
    "fmt"
    "os"
)


func xwrite_stdout(buffer []byte, n_bytes int) {
    if n_bytes > 0 {
        _, err := os.Stdout.Write(buffer[:n_bytes])
        if err != nil {
            fmt.Fprintf(os.Stderr, "error writing %s: %v", "standard output", err)
            os.Exit(1)
        }
    }
}