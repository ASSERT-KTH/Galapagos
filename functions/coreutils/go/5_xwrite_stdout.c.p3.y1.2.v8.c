Although Go doesn't have exact equivalent of every C function, you can approximate the following function by using `os.Stdout.Write` method in Go:

Go
import (
	"fmt"
	"os"
)

func xwrite_stdout(buffer string, n_bytes uint) {
	if len(buffer) > 0 {
		n, err := os.Stdout.WriteString(buffer[:n_bytes]) // We are assuming that n_bytes is always <= len(buffer)
		if uint(n) < n_bytes || err != nil {
			fmt.Fprintf(os.Stderr, "error writing to standard output: %s", err.Error())
			os.Exit(1)
		}
	} 
}


This is a rough equivalent in feature, but you need to replace the string parameter with a slice of bytes if you don't need a string especially since in Go string behaves differently than char array in raw type. Automatic conversion doesn't work and casting can cause problem for non-ASCII characters. Here is more appropriate version.

Go
import (
	"fmt"
	"os"
)

func xwrite_stdout(buffer []byte, n_bytes uint) {
	if len(buffer) > 0 {
		n, err := os.Stdout.Write(buffer[:n_bytes]) 
		if uint(n) < n_bytes || err != nil {
			fmt.Fprintf(os.Stderr, "error writing to standard output: %s", err.Error())
			os.Exit(1)
		}
	} 
}
