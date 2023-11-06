Since Go does not allow variadic parameters at surface level like C does. You must use an interface{}. Further, C uses printf-like format strings, Go uses substitutions. Equivalent substitutions have been used.

Go also does not allow stderr in the same way C does. A special package for error handling is used instead (`github.com/pkg/errors`).
Finally, the `progress_len` in reference not inside provided scope of C function definition so let't assume it's global variable.

Here is Go version for the prescribed problem:

go
package main

import (
	"fmt"
	"github.com/pkg/errors"
)
var progress_len = 1
func diagnose(errnum int, format string, a ...interface{}) {
	if progress_len > 0 {
		tr := errors.New("\n")
		fmt.Printf("%+v", tr)
		progress_len = 0
	}

	newErr := fmt.Errorf(format, a...)
	fmt.Printf("%+v", newErr)
}

Please note `error package` which needs to import to utlize formatted error.