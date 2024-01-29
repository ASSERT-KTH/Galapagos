The equivalent cannot be written exactly the same as original implementation in Golang. As in Golang Variadic functions work differently as compared to C and To they does not offer output or error translation with error no like in C, but following is its nearest counterpart in Golang:

go
import (
	"fmt"
	"os"
	"log"
)

func diagnose(errnum int, fmt string, a ...interface{}) {
	if progress_len := 0; progress_len < 1 {
		fmt.Fprintln(os.Stderr, "")
	}

	l := log.New(os.Stderr, "", 0)

	errFormat := fmt.Sprintf("%s. Error number: %d\n", fmt, errnum)
	l.Printf(errFormat, a...)
}
   

In Golang, instead of streams (like stderr in C) we're using a logger that outputs to stderr. The use of `log.New` function creates a new logger also the 'log' is forcing the output to 'Stderr' as written in original one in C.