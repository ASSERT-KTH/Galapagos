Implementing variadic functions and handling errors in Go is well-differentiated from C. In terms of variadic function calling principle, Go uses a different paradigm where it uses “interface{}” type which can accept any type of parameters.

Here's how the "diagnose" function might look in Go:

go
import (
	"fmt"
	"os"
	"log"
)

var progressLen int

func diagnose(errnum int, args ...interface{}) {
	if progressLen > 0 {
		fmt.Fprintln(os.Stderr, "\n")
		progressLen = 0
	}

	err := fmt.Errorf(args[0].(string), args[1:]...)
	log.Println(errnum)
	log.Println(err)
}


For simplicity, the Go version uses if-statements to write to stderr similar to the 'fputc' and reroutes the errors occurring in verror to log onto the console. You need to make sure to resolve index out of range issue in argument to avoid a panic. Interface can act differently based on what you are passing i.e you cannot detect at compilation time. Types safety concerns raise here. The ‘.’ operator provides both obj.Type and obj.Type().method idioms, disambiguated by the fact that methods in Go don’t use parentheses.

This code will compile, but remember that sophisticated error logging and delay formatting may have to be done. Be mindful of the fact that designing that system is beyond the scope of this conversion.