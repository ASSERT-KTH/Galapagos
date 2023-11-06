import (
    "os"
    "fmt"
)

func xwrite_stdout(buffer []byte, n_bytes int) {
    if n_bytes > 0 {
        _, err := os.Stdout.Write(buffer[:n_bytes])

        if err != nil {
            fmt.Println("error writing standard output:", err)
            os.Exit(1)
        }
    }
}