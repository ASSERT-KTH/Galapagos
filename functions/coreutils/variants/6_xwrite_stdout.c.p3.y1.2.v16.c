As opposed to C, Go's philosophy aims to make errors values that programmers can manage directly. As such, Go does not follow the C function convention, it typically uses (result, error) on function signature to manage them, notably on its IO related API. However, translating as close as possible would look something like this:

go
import (
	"os"
	"fmt"
)

func xwrite_stdout(buffer string, n_bytes uint) {
	if n_bytes > 0 {
		n, err := os.Stdout.Write([]byte(buffer[:n_bytes]))
		if err != nil || uint(n) < n_bytes {
			if err := os.Stdout.Sync(); err != nil {
				panic(fmt.Sprintf("error flushing standard output: %v", err))
			} else {
				panic(fmt.Sprintf("error writing standard output: expected to write %d bytes but wrote %d", n_bytes, n))
			}
		}
	}
}
 

This version of the function takes care of the key logic that if the number of bytes to write is greater than zero, it attempts to write to standard output. In the event it fails due solely to a Sync Error, it will output a message stating so, formatted with the error details. Likewise if the bytes written were not the expected count, then an error message would display what was expected versus the result. The panic calls can be caught using the recover function at the top-level execution flow if necessary. However be aware that it’ll terminate the program if not caught and handled, as opposed to simply closing the standard output in the C function.