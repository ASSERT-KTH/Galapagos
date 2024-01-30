import (
    "fmt"
    "os"
    )

func write_error() {
    error := fmt.Errorf("write error")
    fmt.Fprintln(os.Stderr, error)
    os.Exit(1)
}