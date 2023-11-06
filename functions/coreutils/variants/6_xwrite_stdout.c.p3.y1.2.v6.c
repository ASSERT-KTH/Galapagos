go
import (
    "fmt"
    "os"
)

func xwrite_stdout(buffer string, n_bytes uint) {
    if n_bytes > 0 {
        n, err := os.Stdout.WriteString(buffer)
        if err != nil || uint(n) < n_bytes {
            fmt.Fprintf(os.Stderr, "error writing %s", "standard output")
            os.Exit(1)
        }
    }
}
