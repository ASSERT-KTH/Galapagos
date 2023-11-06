Unfortunately, you can't directly implement equivalent code in Go, because Go disapproves the loading of the functions dynamically at runtime as C supported via `dlsym()`.

However, to accomplish the equivalent use of exit(int status) function that waits 100 milliseconds before exiting, you can use "os.Exit()" function together with the "time package". 

Please find below a rough equivalent example of how to delay execution before exiting a application in Go:

go
package main

import (
	"os"
	"time"
)

func exit(status int) {
	time.Sleep(100 * time.Millisecond)
	os.Exit(status)
}


Again, please note that Go doesn't support dlsym method or another precise replacement for treating raw function pointers. Static types and a garbage-collected runtime makes handling raw function pointers problematic in Go environment.