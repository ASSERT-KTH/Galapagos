import (
    "fmt"
    "os"
)

func xwrite_stdout(buffer []byte, n_bytes int) {
    if n_bytes > 0 {
        numBytes, err  := os.Stdout.Write(buffer[:n_bytes])
        if err != nil || numBytes < n_bytes {
            fmt.Fprintln(os.Stderr, "Error: failed to write to standard output")
            os.Exit(1)
        }
    }
}