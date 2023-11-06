It's impossible to have an exact line-by-line translation of this C code into Go, mainly given that Go does not provide way to access and modify external variables like `progress_len` directly, Go also doesn't have a direct way to handle varargs like C via `va_list`. 

Also, 'verror' function in your C function refers to a function that maps an error number to an error message equivalent to the error description associated with ernum, and also prints the message using a predefined format. In Go, error handling is generally done via return values and not through error numbers similar to errno in C.

Translation would require understanding and potentially restructuring the application. Also this code has also dependencies on other functions. So, part of this function such as "verror" function should be redesigned in Go language by you based on your own project layout.

The translated concept could be similar to this in Go:

go
import (
	"fmt"
	"os"
)

func diagnose(err error, format string, a ...interface{}) {
	if progressLen > 0 {
		fmt.Fprintln(os.Stderr, "")
		progressLen = 0
	}

	errMsg := fmt.Sprintf(format, a...)
	if err != nil {
		errMsg += ": " + err.Error()
	}
	fmt.Fprintln(os.Stderr, errMsg)
}
                           

Please note where is used such line as `import "os"`, as far as the standard error stream in golang is provided in the `os` package. Please do replace `progressLen` with correct according to your implied context variable referenced as `progress_len` in original C code.

Above Go code does not give the same stack trace output or mapping of an error number to an error message equivalent to the C version (the verror function). We treat err as an already composed error message. The fmt are the format string and the variadic values used to fill it.
Also 'verror' and `progress_len` were referenced within the function but not visible in the function code you posted. It's thus unknown what they should do or what datatypes they are.