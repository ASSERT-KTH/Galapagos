In Go, variadic functions are typically handled through the `fmt.Sprintf` function from the `fmt` package to generate a formatted string, and the `log` package to output the error message. However, please note that due the differences between C and Golang, particularly in terms of error handling and variable arguments, the semantic translations might not be exactly the same. 

Here is a Golang version of your C function:

go
import (
	"fmt"
	"log"
	"os"
)

var progress_len int // It should be defined somewhere in your Go code

func diagnose(errnum int, format string, a ...interface{}) {
	if progress_len > 0 {
		fmt.Fprint(os.Stderr, "\n")
		progress_len = 0
	}

	msg := fmt.Sprintf(format, a...)
	err := fmt.Errorf("ErrNum: %d, Msg: %s;", errnum, msg)
	// Consider to handle error object rather than log it directly
	log.Fatal(err)
}
 

There is no direct translation for `va_start`, `va_end` in Golang because in Golang you simply use the `...interface{}` type to denote a variadic function that accepts a variable number of arguments. 

Please remember that in Go, you usually want to return errors. Promptly exiting the program using `log.Fatal` is not a common practice, because this function call will terminate the program immediately after writing the log message. You would generally want to return an error to the calling function and let it decide how to handle the error.