Here is the Go version of the C function. However, it's important to note that there is no direct equivalent in Go for variadic functions that accept different types of arguments (like printf in C). Made changes to the function accordingly.


import "fmt"
import "os"

var progress_len int

func diagnose(errnum int, fmtstring string, a ...interface{}) {
	if progress_len > 0 {
		fmt.Fprintln(os.Stderr)
		progress_len = 0
	}

	fmt.Fprintf(os.Stderr, fmtstring, a...)
	os.Stderr.WriteString(fmt.Sprintln(errnum))
}
