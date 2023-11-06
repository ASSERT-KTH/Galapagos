Please notice that the Go language does not currently officially support variadic function argument forwarding, like the "..." notation in the presented C function. Go's `fmt.Printf` style functions make use of an interface slice (`...interface{}`) to achieve their variable argument functionality.

Furthermore, Go uses a drastically different error system from many C based languages and does not have an equivalent to ERR_COMP, so for meantime, the `com_err_va(concat string, codes errcode_t, variables ...interface{})` function must be manually implemented.

Given these constraints, an equivalent function to fit Go standards that remains as close in form and functionality could like the following:

go
import (
	"fmt"
)

type errcode_t int 

func com_err(whoami string, code errcode_t, format string, a ...interface{}) {
	finishedFormat := fmt.Sprintf("%s %d: %s\n", whoami, code, format)
	fmt.Printf(finishedFormat, a...)
}


The variadic arguments compose the data to be printed by '%v' in Sprintf. Please pay attention to include another suitable logic into the function `com_err`, if you have an exactly error handling flow to replace the original one.