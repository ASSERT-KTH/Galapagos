go
import (
	"fmt"
	"os"
)

func xwriteStdout(buffer []byte, nBytes int) {
	if nBytes > 0 {
		_, err := os.Stdout.Write(buffer[0:nBytes])
		if err != nil {
			os.Stdout.Sync()
			fmt.Fprintln(os.Stderr, fmt.Sprintf("error writing %s: %v", "standard output", err))
			os.Exit(1)
		}
	}
}
