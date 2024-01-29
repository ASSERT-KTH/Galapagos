Here is a semantically equivalent version of the provided C code, translated to the Go programming language:

Go
package main

import (
	"fmt"
	"os"
)

func writeError() {
	savedErrno := os.NewSyscallError("write", os.Errno())
	if err := os.Stdout.Sync(); err != nil {
		fmt.Fprintln(os.Stderr, "Error flushing buffer:", err)
    }
	if err := os.ClearBuff(os.Stdout); err != nil {
		fmt.Fprintln(os.Stderr, "Error clearing buffer:", savedErrno)
	} else {
		fmt.Fprintln(os.Stderr, "Error writing:", savedErrno)
		os.Exit(1)
	}
}


Do note:

- In the `Sync()` call, the semantics map fairly closely to 'flushing' in C. Go provides `Sync()` function to make sure all buffered operations have been applied to the underlying writer.
  
- There is no direct equivalent to `clearerr()` function in C. Instead, an alternative approach taken here by clearing the buffer for Stdout using an assumed user implementation - `ClearBuff()`. This will depend upon actual implementation and may differ based on how you handle it in your actual usage.
- The `EXIT_FAILURE` is represented by the `os.Exit(1)`, and Go doesn't translate errno's to usable text directly, hence `os.NewSyscallError()` used to create a new error with `write` as a description and providing `os.Errno()` which saves the last error from an OS call as in the originally program.
- Lastly, the C named parameter approach `error(EXIT_FAILURE, errno, <str>)` converted into Go's print line feature to have an equivalence routine.