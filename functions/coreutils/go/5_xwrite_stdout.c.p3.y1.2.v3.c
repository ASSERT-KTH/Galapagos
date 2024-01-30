Here is an example of how you can implement this in Go:

go
import (
    "fmt"
    "os"
)

func xwrite_stdout(buffer string, n_bytes int) {
    if n_bytes > 0 {
        // Convert string to Slice cause Writer.Write need []byte parameter
        byt := []byte(buffer)
        _, err := os.Stdout.Write(byt[:n_bytes])
        if err != nil {
            fmt.Printf("Error writing %s\n", "standard output")
            os.Exit(1)
        }
    }
}


It's worth noting that Go doesn't support the direct equivalent of `error()` and `EXIT_FAILURE`. This program will go to the nearest accessible explanation with `os.Exit(1)`, but remember that strictly speaking, it is not a direct analogous equivalent. Consider adding graceful error management in agreement with Go's philosophies about handling errors.