Golang does not directly support variable argument lists in the same manner as C does. Moreover, Golang doesn't have the concept of functions like `va_start` and `va_end` to handle variable number of arguments as it supports variadic function i.e., where the last parameter is of a type prefixed with an ellipsis `...`, allowing for any number of parameters of this type. Here is the equivalent function in Go.

go
package main

import "fmt"
import "log"

type errCode int

const(
	whoami = "some_task"
	cCode  = errCode(2) 
)

func comErr(who *string, ersCode errCode, a ...interface{}) {
	callComErrVa(who, ersCode, a)
}

func callComErrVa(who *string, ersCode errCode, a ...interface{}) {
	// All standard log functionalities
	str := fmt.Sprint(a...)
	// Adding 'whoami', code and then string formatted in next step
	log.Println("Error With:", *who, "type", ersCode, "with", str)
}

func main() { // For test
	comErr(&whoami, cCode, "try", "something", "and", "fail")
}

Included an auxiliary function for context perspectives. As the Go signatures and arguments processing is much more different than that of C, it is not feasible to follow 100% the same way.

User os to work further with Error types or using a general implementation. Go encourages specific errors for better error understanding, so exact clone will not be feasible because Go's ideology is different in error handling from C. Please modify this code to use log level or producing suitable system operation call like actions based on your environment.