Sorry, but it's not possible to translate this function identically into Go. Here's why:

1. Variadic arguments in C and Go work differently. You can't get a list of arguments directly as in C with va_list, va_start, etc., in Go.

2. Your function appears to use error handling via an error number (errnum parameter) in traditional C error-handling fashion. Whereas in Go, errors is a built-in type that can contain relevant information for error reporting.

3. The function verror does not have a direct equivalence in Go. However assuming it prints the custom error message to stderr, this can be approximated using fmt package in Go.

4. "progress_len" as global variable in C code and its usability would differ in Go since Go discourages the use of global state. Without knowing the intent and relation of progress_len in your business logic its translation would be effectively limited.

So, not strictly identical, but based on all the assumptions above a semantic approximation in Go could look like:

Go
import (
	"fmt"
	"os"
)

func diagnose(errnum int, format string, a ...interface{}) {
	if progress_len > 0 {
		fmt.Fprintln(os.Stderr)
		progress_len = 0
	}

	err := fmt.Errorf(format, a...)
	if err != nil {
		fmt.Fprintln(os.Stderr, err)
	}
}


In this proposed Go version, progress_len would not be global and its initialisation / modification should be taken care of external to diagnose(). Please revise "progress_len" usage consistent to Go best practices. Compared to original C version where stderr is explicitly supposed to be used for writing, Go usually employs os package that provides equivalent functions. Error is still printed to stderr._error instead of having msg communicated through a system errno.

This translation is rough guesswork without the full understanding of your business logic and might not correctly translate your intentions behind 'errnum' and 'progress_len' usage in C code. You might have to extent it further or deviate depending on what other requirements you have beyond those visible in this single function. C and Go languages recognize different paradigms, mainly concerning error handling which in small snippets might look trivial but becomes significant for system-level applications. Care must be taken to translate overall compatibility in addition to semantics.