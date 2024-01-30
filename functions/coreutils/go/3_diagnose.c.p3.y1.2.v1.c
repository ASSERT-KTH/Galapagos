In Go, function `diagnose` might look like this:

go
import (
	"fmt"
	"log" 
	"os"
)

var progress_len int

func diagnose(errnum int, fmt string, a ...interface{}) {
	if progress_len > 0 {
		fmt.Fprintf(os.Stderr, "\n")
		progress_len = 0
	}

	log.Printf(fmt, a...)
	if errnum != 0 {
		log.Printf("\nErrno: %d", errnum)
	}
}


Please note that Go achieves variable function arguments with `...interface{}` type and not all inherent C features translate directly. Also note that this Go function, though similar in purpose, may not exactly match the behavior of the C function `verror`, part of GNU's lib-error for formatted error messages, as there's no direct equivalent in Go. The `log` package in Go usually handles log-related tasks and makes possible to write formatted, variable amount error but natively it writes to standard error and possibly your default logger destination.