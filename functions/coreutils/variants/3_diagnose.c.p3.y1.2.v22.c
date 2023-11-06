Unfortunately, there is no complete equivalent function in Go because Go does not support variadic functions in the same way C does. But still below is a similar class function of C function in Go which would give an errorlog output based on an error number and a formatted string.

go
import (
	"fmt"
	"os"
)

var progress_len int

func diagnose(errnum int, fmtStr string, a ...interface{}) {
	if progress_len > 0 {
		fmt.Fprintln(os.Stderr, "")
		progress_len = 0
	}

	err := fmt.Errorf(fmtStr, a...)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error %d: %v\n", errnum, err)
	}
}


This example in Go uses spaces to separate the variables, while the C example does not. It also ends with a newline, while the C version does not.