In Go, error handling is substantially different, and does not have direct equivalents for the exact C functions used in the examples. However here is an effort to capture the similar semantics in Go:

Go
import (
	"bufio"
	"fmt"
	"os"
)

func writeError() {
	writer := bufio.NewWriter(os.Stdout)

	errNo := writer.Flush()
	if errNo != nil {
		fmt.Println("Flush Error: ", errNo)
		os.Exit(1)
	}
	os.Stdout.Sync()
	os.Stderr.WriteString("write error")
	os.Exit(1)
}

Here is an explanation on the above code:

1. Go doesn't have an equivalent package/function to directly handle `errno`.
2. `fflush(stdout)` equivalent in Go is `bufio.Writer.Flush()`, where bufio.Writer should have reference of Stdout.
3. `clearerr(stdout)` equivalent in Go is `os.Stdout.Sync()`.
This returns an error if any, which then takes the Go approach to handling errors.
4. `EXIT_FAILURE` - typically this would invoke the `os.Exit()` call, passing in an int value `1`, to indicate error/unsuccessful termination. Note that you might want to use a more descriptive or meaningful exit/error code in a real development context.
5. The writeError similar behavior can be mimicked using a simple write to stdout - note that you might want to handle/log errors differently in a proper development context. 
6. Linux OS will free all resources let it be files, buffers etc. So no need to clear error specifically.
7. `_` is not a Go idiom, so instead we're using standard error reporting. In real code, you might want to use error-wrapping and custom error types.