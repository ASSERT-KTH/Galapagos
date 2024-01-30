go
import (
	"fmt"
	"os"
)

func xwrite_stdout(buffer string, n_bytes int64) {
	if n_bytes > 0 {
		n, err := os.Stdout.Write([]byte(buffer)[:n_bytes])
		if err != nil || int64(n) < n_bytes {
			fmt.Fprintln(os.Stderr, "error writing standard output: ", err)
			os.Exit(1)
		}
	}
}
