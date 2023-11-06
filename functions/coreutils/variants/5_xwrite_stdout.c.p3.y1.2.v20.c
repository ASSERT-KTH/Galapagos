go
import (
	"fmt"
	"os"
)

func xwrite_stdout(buffer string, n_bytes int) {
	if n_bytes > 0 {
		bytesWritten, err := fmt.Fprint(os.Stdout, buffer[:n_bytes])

		if err != nil || bytesWritten < n_bytes {
			fmt.Fprintf(os.Stderr, "error writing %s\n", "standard output")
			os.Exit(1)
		}
	}
}
