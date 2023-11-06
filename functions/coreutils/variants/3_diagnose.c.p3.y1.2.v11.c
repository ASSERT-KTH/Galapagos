In Golang, we don't have direct equivalent methods or constructs for some C constructs used in assigned function. 

Functioning of `va_list`, `va_start`, `va_end` etc can be achieved through interfaces in Go, but exact functioning of `verror()` cannot be replicated since Go's standard library does not have this function and also error handling is little different in Go. 

Also, for printing to `stderr`, we generally write byte slices in `os.Stderr` directly or use logging functions, hence `fputc()` also does not have a direct equivalent.

closet possible solution is:

go
import (
	"fmt"
	"os"
	"log"
)

var progressLen int

func diagnose(errnum int, fmtStr string, args ...interface{}) {
	if progressLen > 0 {
		fmt.Fprint(os.Stderr, "\n")
		progressLen = 0
	}
	msg := fmt.Sprintf(fmtStr, args...)
	_, err := fmt.Fprintf(os.Stderr, "error number: %d, error: %v", errnum, msg)
	if err != nil {
		log.Printf("Failed to write to stderr: %v", err)
	}
}

Please update according to your requirements in Go.

Also, `progress_len` could not be found in original method, it is assumed as a global integer variable in solution above. Please ensure its value should be managed accordingly outside of this function.