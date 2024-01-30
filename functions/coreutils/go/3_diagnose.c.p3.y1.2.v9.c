Unfortunately, recreating this exact same function in Go is not entirely possible due to some language differences between C and Go. 

Go does not support variable arguments in the same way that C does with `va_start`, `va_end`, and `vprintf`. Further, Go does not support directly manipulating standard error like C does through `stderr`.

However, equivalent Go code following the intention of the C function could look as follows.

import (
	"fmt"
	"log"
	"os"
)

var progress_len int

func diagnose(errnum error, format string, a ...interface{}) {

	if progress_len > 0 {
		fmt.Fprintln(os.Stderr, "")
		progress_len = 0
	}
	
	str := fmt.Sprintf(format, a...)
	if errnum != nil {
		str += ": " + errnum.Error()
	}

	log.Println(str)
}

In the above Go code, `errnum` parameter is considered an `error` type and `log.Println` function is used instead to print error (formatted message) to `stderr` per idiomatic Go style. Variable arguments are included as an additional parameter to enable format printing. Since Go does not automatically recognize C convention, we use `os.Stderr` for directing the output to standard error. The global variable `progress_len` is used as example, but note that managing state through global variables is generally discourage in Go. The implemented differences are mainly stemming from the abstractions that Go's linguistic environment includes over C's more manual memory management and preprocessor macros. However, Go's features endow it with guarantee type safety impervious to certain common C stubbles.