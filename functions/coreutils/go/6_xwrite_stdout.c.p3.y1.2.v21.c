import (
	"fmt"
	"os"
)

func xwrite_stdout(buffer []byte, n_bytes int) {
	if n_bytes > 0 {
		n, err := os.Stdout.Write(buffer[0:n_bytes])
		if n < n_bytes {
			if err != nil {
				fmt.Fprintln(os.Stderr, "error writing standard output:", err)
			}
			os.Exit(1)
		}
	}
}