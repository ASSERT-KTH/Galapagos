It's important to note that the function com_err in the original C code makes use of a variable number of arguments feature which, unfortunately, isn't supported directly in Go.

In Go, a slice of the interface{} type serves as a mean for passing variable number of arguments of any type, but changing the type of an argument changes the function's signature. So, the best way to address this issue without changing function's signature might be using the equivalent of Go's fmt.Sprintf that duplicates the behaviour of com_err_va. 

Also note that Go does not have function overloading directly nor distinguishing among various data types without reflection which can change the performance aspect of a function.

Here is a semantically equivalent approximation in Go:
go
package main

import (
    "fmt"
    "log"
)

func comErr(whoami string,
    code int,
     formatMessage string, arguments ...interface{}) {
    
    if code != 0 {
        formattedMessage := fmt.Sprintf(formatMessage, arguments...)
        errMsg := fmt.Sprintf("%s : [%d] %s", whoami, code, formattedMessage)
        log.Println(errMsg)
    }
}

Usage of comErr function:
go
func main() {
    comErr("Me", 1, "encounters error %s", "out of nowhere")
}

The result should be:
	Me : [1] encounters error out of nowhere