go
import (
    "fmt"
    "os"
    "syscall"
)

func xwriteStdout(buffer []byte, n_bytes int) {
	if n_bytes > 0 {
		_, err := os.Stdout.Write(buffer[:n_bytes])
		if err != nil {
			fmt.Fprintf(os.Stderr, "Error writing to standard output: %s", err)
			os.Exit(1)
		}
	}
	os.Stdout.Sync()
}
