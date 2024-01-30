import (
	"fmt"
	"io"
	"os"
)

func xwrite_stdout(buffer []byte) {
	if len(buffer) > 0 {
		_, err := os.Stdout.Write(buffer)
		if err != nil {
			fmt.Fprintf(os.Stderr, "error writing %s: %v\n", "standard output", err)
			os.Exit(1)
		}
	}
}