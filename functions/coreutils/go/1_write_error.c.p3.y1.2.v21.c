The translation of this function to Go language requires understanding the purpose of the C version. Here is an approximate implementation, due to the difference between C and Go:

go
import (
    "fmt"
    "os"
)

func writeError() {
	// We cannot get a direct equivalent of saved_errno in Go,
    // instead we handle errors when they occur

	// stdout.Flush ensures nothing buffered that might induce an  error.
    err := os.Stdout.Sync()
    if err != nil {
       fmt.Fprintf(os.Stderr,"write error: %v\n", err)
       os.Exit(1)
    }

	/* Clearing errors isn't really possible in an equivalent Go version,
	as Go just handles errors when they occur, it doesn't track 
	'errno'. Instead we handle Error when stderr fails to write output */

    _, err = fmt.Fprintln(os.Stderr, "write error")
    if err != nil {
       fmt.Fprintf(os.Stderr,"write error: %v\n", err)
       os.Exit(1)
    }
    
    os.Exit(1)
}


The C function follows a pattern of "check for errors, report if any". Go uses an "attempt operation and handle errors" type pattern, which gives the functionality 'error check, if anything goes wrong, report!' When an error occurs, Go programs will use `os.Exit(1)` in a similar manner to `EXIT_FAILURE`.

Please, adapt if needed, since Go programming style encourages checking errors when they happen and not preserving errors like errno in C.