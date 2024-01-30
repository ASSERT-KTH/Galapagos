In Go, creating a function with the same variable arguments like the C function posted is impossible due its lack of support for such structure. However, we can replace the variable argument list (...) with a slice. Also the errorcode type errcode_t is unknown in Go, instead we will use the built-in error type.

go
package main

import (
	"fmt"
	"log"
)

func com_err(whoami string, code error, fmtArgs ...interface{}) {
	msg := fmt.Sprintf(whoami, fmtArgs...)
	
	if code != nil {
		msg += ": " + code.Error()
	}
	
	log.Println(msg)
}


You may want to adjust the logging behavior according to your needs, `log.Println(msg)` is just used for simplicity.