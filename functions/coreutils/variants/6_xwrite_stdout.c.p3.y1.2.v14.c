Go doesn't directly support error codes like C; instead it relies on returned error values. Also, it exposes the desired function through different abstractions:

go
import (
	"fmt"
	"os"
)

func XWriteStdout(buffer []byte) {
	if len(buffer) > 0 {
		n, err := os.Stdout.Write(buffer)
		if err != nil || n < len(buffer) {
			fmt.Fprintln(os.Stderr, "Error writing standard output")
			os.Exit(1)
		}
	}
}


In the Go version of function, instead of taking a char pointer and size as C did, it takes a `[]byte` which is more analogical. Function os.Stdout.Write handles ensuring data is written to standard output device and the error returned is its corresponding analog in Golang. 

Support for EXIT_FAILURE and formatting internationalization isn't provided or called by inbuilt Golang packages although third-party packages are mostly used in real-life software development, for these requirements which are not provided by your original specification. If you still insist on this functionality, it would require learning additional, complex concepts or involving third-party  packages, so we should deviate as little as possible.

The exit program shows the failure returned if an exit failure occurs in C; we'll use os.Exit(1) to do the same. Other error writings in terms of errno and ("standard output") might need third-party packages as mentioned above which deviate more from the initial requirements.