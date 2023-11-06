import (
    "fmt"
    "os"
)

func write_error() {
    _, err := fmt.Fprintln(os.Stdout)
    if err != nil {
        fmt.Fprintf(os.Stderr, "write error: %v\n", err)
        os.Exit(1)
    }
}