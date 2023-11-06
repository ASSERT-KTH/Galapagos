Go has built-in functionality that allows Go programs to define specific actions or delays etc. according to the requirement of the program. However, Go doesn't offer dynamic linking/loading native implementation like C/C++ and there are no built-in time delay equivalent function calls in Go. Neglecting these factors following is the best possible equivalent of the given function in Go:

go
package main

import (
	"fmt"
	"os"
	"time"
)

func exit(status int) {
	// sleep for 100000 microseconds equivalent
	time.Sleep(100 * time.Microsecond)

	// equivalent of exit status 
	os.Exit(status)
}

Note: However, this code doesn't intentionally introduce the delay before the process termination.

The delay mimics the select function call in C code, The use of os.Exit(status) provides the exit functionality exactly the same way as the provided C code. We can't override system function so writing a function with exactly same name i.e. 'exit' won't be achievable. It'll cause a conflict with os.Exit method. Adjust the name accordingly.