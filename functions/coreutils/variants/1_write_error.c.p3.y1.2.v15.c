Unfortunately, due to significant differences between the C and Go programming languages, the exact replication of the provided C function is technically not feasible in Go, especially because Go does not have the ability to manipulate file buffers at the same low level. However, you can achieve a similar result by using Go's built in Error function for handling standard errors and the "os" package for handling file-related operations:

go
import (
	"fmt"
	"os"
)

func writeError() {
	err := os.Stderr.Sync() // equivalent to fflush in C

	if err != nil {
		fmt.Fprintf(os.Stdout, "write error: %s", err)
		os.Exit(1) // equivalent to EXIT_FAILURE in C
	}

	// Error handling if any other kind of write operation increased error state.
	// Using fmt and os for creation of error message.
	err = fmt.Errorf("write error: %s", os.ErrInvalid) 
	if err != nil {
		fmt.Fprintf(os.Stdout, "%s", err)
		os.Exit(1)
	}
}

Please note that errors in Go are not represented in the same way as in C. The code sample provided here attempts to provide equivalent functionality to your C code by checking for error conditions and (where necessary) provide the caller with an error message similar to the C original code. We don't have the errno behavior in Go, because Go uses a different error model than C. Instead, a Go function that can fail returns an additional result (the error). Therefore, this is a functional approximation to your original C function. However, it may slightly vary under more specific error management requirements.