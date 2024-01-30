import (
    "os"
    "fmt"
)

func xwrite_stdout(buffer string, n_bytes int) {
    if n_bytes > 0 {
        _, err := fmt.Fprintf(os.Stdout, "%s", buffer[:n_bytes])
        if err != nil {
            fmt.Fprintf(os.Stderr, "error writing %s: %s", "standard output", err)
            os.Exit(1)
        }
    }
}