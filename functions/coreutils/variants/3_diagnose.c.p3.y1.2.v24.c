Because Go does not provide an exact equivalent to C's variadic functions and `va_start , va_end` is used for these variadic function in C which is not supported by Go. Go uses the ... notation enable the use of the variadic function.
However, Go's `fmt` package, allows us to accomplish something similar. We can both interpret variable number of arguments and format strings, even though the mechanism isn't quite the same as in C.

There's also no exact match for C's `verror` function in Go so below does the closest transliteration I could come up with:

go
import (
	"fmt"
	"os"
	"log"
)

var (
	progress_len int
)

func diagnose(errnum int, f string, a ...interface{}) {
	if progress_len > 0 {
		_, err := fmt.Fprintln(os.Stderr, "")
		if err != nil {
			log.Fatalf("fprintln error: %v", err)
		}
		progress_len = 0
	}

	msg := fmt.Sprintf(f, a...)
	_, err := fmt.Fprintln(os.Stderr, msg+" Error Number: "+fmt.Sprintf("%d", errnum))
	if err != nil {
		log.Fatalf("fprintln error: %v", err)
	}
}
 

Note the use of "...interface{}" to mark a variadic function, and the call to fmt.Sprintf to format the error message. 

This won't work exactly the same as the original C code as the original is able to take essentially any combination of fmt/error message parameters, and Go's variadic functions (`a ...interface{}`) can't quite match that.
