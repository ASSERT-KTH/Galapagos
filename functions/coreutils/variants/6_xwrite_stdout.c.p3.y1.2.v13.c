The equivalent function in Golang would be as follows:

go
import(
   "os"
   "fmt"
)

func xwrite_stdout(buffer string, n_bytes int) {
    if n_bytes > 0 {
        _, err := os.Stdout.Write([]byte(buffer[:n_bytes]))
        if err != nil {
           fmt.Fprintf(os.Stderr, "error writing %s: %s", "standard output", err)
           os.Exit(1)
        }
    }
}
