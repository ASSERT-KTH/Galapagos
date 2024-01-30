Go does not support Variadic Function similar to C++, and there are differences between error handling in Go and C that makes a 1-1 conversion of this C function nontrivial. However, here's a Go implementation that's as close as possible but not be mistake with earlier statement:
Go
import (
	"fmt"
	"errors"
)

type ErrCode int  // Alias for errcode_t in C

func ComErr(whoami string, code ErrCode, format string, a ...interface{}) error {
	formattedError := fmt.Sprintf(format, a...)
	finalError := fmt.Sprintf("%s - Error code: %d - %s", whoami, code, formattedError)
	return errors.New(finalError)
}

In this Go function, any number of arguments after `format` string can be passed which will be used to format the error string. Format specifiers in `format` string should match the number and types of extra arguments.

This function will create formatted string, include in final error it `whoamI`, `ErrCode` and formatted string, and then returns error using built-in `errors.New()` function in Go. 

The client of this function can then handle this error as appropriate, for example by logging it, or panicking if it's a fatal error. One main convention in Go is to always return errors to the caller of function, Do not panic within library and utility functions.