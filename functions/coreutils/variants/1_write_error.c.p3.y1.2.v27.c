In the Go coding language, error handling is typically different than in C for numerous reasons, and in Go, it's usually done using the strategy "return the error value", rather than setting a global variable, as in C. However, to adhere to the approach taken in the given sample, the function could be translated as follows:

go
import (
	"os"
	"fmt"
)

var savedError error 

func writeError() {
	stddout_fsync()
	clearErr()

	if savedError != nil {
		fmt.Fprintf(os.Stderr, "write error: %v\n", savedError)
		os.Exit(1)
	}
}

func stddout_fsync() {
	// There is no equivalent fflush function in Go. However, in Go,
	// writes to os.Stdout are unbuffered by default.
}

func clearErr() {
	// Inconsistent to C, unlike errno which is a global error variable, 
	// Go has a specific error return and where needed, will require manual resetting.
	// However, we might use something like this
	savedError = nil
}

Please note:

1) Every funcion that might set the savedError must ensure to set it back once no longer needed. In Go, error reporting and handling should generally be done explicitly, you would usually want to refactor your error handling approaches when translating software from C to Go.

2) There are no direct equivalents in Go for fflush and clearerr functions provided in C. Adding or taking necessary steps depends mainly on what follows and precedes this implementation.

3) Capturing or having a set of error types might also be necessary thus added to the translation depending on the particular functions and operations interacting with the writeError().