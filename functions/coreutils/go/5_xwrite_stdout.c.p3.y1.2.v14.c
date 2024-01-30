import (
	"fmt"
	"os"
)

func xwriteStdout(buffer []byte, nBytes int) {
	if nBytes > 0 {
		n, err := os.Stdout.Write(buffer[:nBytes])
		if err != nil || n < nBytes {
			fmt.Fprintf(os.Stderr, `error: failed writing "standard output": %v`, err)
			os.Exit(1)
		}
	}
}