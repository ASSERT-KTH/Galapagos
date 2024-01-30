Go does not support variable function arguments in exactly the same way as C; however, Go's "interface{}" type, combined with the "..." argument syntax, can often be used to achieve similar functionality. For this problem, log.Println of the standard library package log seems appropriate.

Your function in Go would look like this:

go
import (
	"fmt"
	"log"
)

var progressLen int

func diagnose(errnum int, format string, a ...interface{}) {
	if progressLen > 0 {
		fmt.Fprintln(os.Stderr, "")
		progressLen = 0
	}

	text := fmt.Sprintf(format, a...)
	log.Println(fmt.Sprintf("%d: %s", errnum, text))
}

In the Go code, `log.Println()` will automatically add newline character after each call similar to `fputc()` doesn't do it in between stdout or stderr as in your C function, so to take newline character into account in strictly following translation was not possible.

Please note we are assuming, but not allocating, `progressLen` and how it interacts with the rest of the system as it was missing in the given context.