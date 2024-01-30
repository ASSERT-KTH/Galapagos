Given the specifics of the problem, a direct and complete equivalent in Go won't be possible due to the differences in languages' error handling and varying levels of control. However, we can write a rough translation of this C code to Golang.

go
import (
	"fmt"
	"os"
)

func xwrite_stdout(buffer string, n_bytes int64) {
	if n_bytes > 0 {
		numBytes, err := os.Stdout.Write([]byte(buffer))
		if err != nil || numBytes < int(n_bytes) {
			fmt.Fprintf(os.Stderr, "error writing %s\n", "standard output")
			os.Exit(1)
		}
	}
}


In Go, the bytes written number and the error are returned together compared to only error being returned in the original C function. Further in Go, 'os.Stdout.Write' would be used which already clears errors after the fact, thus 'clearerr ()' isn't needed. There is also no drop-in equivalent for 'exit()' function in Go but having it there gives an approximate conversion of the C function.