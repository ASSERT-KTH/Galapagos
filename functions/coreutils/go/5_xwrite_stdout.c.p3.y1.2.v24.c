import (
    "fmt"
    "os"
)

func xwrite_stdout(buffer string, n_bytes int) {
    if _, err := os.Stdout.Write([]byte(buffer[:n_bytes])); err != nil {
        fmt.Print("error writing standard output")
        os.Exit(1)
    }
}