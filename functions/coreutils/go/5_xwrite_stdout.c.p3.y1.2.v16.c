go
import (
	"fmt"
	"io"
	"os"
)

func xwrite_stdout(buffer string, n_bytes int) {
	if n_bytes > 0 {
		_, err := io.WriteString(os.Stdout, buffer[:n_bytes])
		if err != nil {
			fmt.Printf("error writing: %v\n", "standard output")
		}
	}
}
