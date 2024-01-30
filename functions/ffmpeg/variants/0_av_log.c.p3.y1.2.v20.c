In Go, there's no direct equivalent to variadic arguments like in C. Therefore, we would change the function signature slightly to substitute variadic arguments using ...interface{} (it’s the Go way to manage an arbitrary number of arguments varying by type).

Here's the code:

go
package main

import (
	"log"
)

func AVLog(avcl interface{}, level int, fmt string, v ...interface{}) {
	log.Printf(fmt, v...)
}

This function uses Go's built-in "log" package. The Printf function formats according to a format specifier and writes to the log output. Arguments are formatted and output according to the format specifier. If the format includes verbs (like %s and %d), then 'v' will substitute the verbs in the format string. 
Note that Printf functions are variadic, and handle a list of values as parameter using v ...interface{}; this is the concept provided by Go which performs identical functionality as in input version.  

Also take into account that this example applies default logger’s output rules, which add crucial information like timestamp and code line which called the log functions. In robust solution you may want to use log.New() for creating separate logger preferences.

Please note, variadic function in Go deals with parameters differently than the varargs in C and so va_list, va_start and va_end have no direct equivalent in Go.