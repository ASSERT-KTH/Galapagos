There's no way to do a direct conversion from C to Go on this code snippet, especially one that maintains the function signature but we can create a semantically similar function:

Go
package main

import (
	"os"
)

func xwrite_stdout(buffer string, n_bytes int) {
	if n_bytes > 0 {
		buf := []byte(buffer)
		if count, err := os.Stdout.Write(buf[:n_bytes]); count < n_bytes || err != nil {
			panic("error writing standard output")
		}
	}
}


In this function, we're ensuring that we have written the exact number of bytes specified by `n_bytes` into the `stdout`. If not, we throw a panic.

Please bear in mind that:

1. Go is more advanced in error handling since the error type can carry more information. You should handle this error in a more sophisticated way instead of just printing thanks to sophisticated error handling in Go.

2. Go doesn't have equivalent function for `quoteaf`. So, exact match/translation isn't possible. 

3. Global variables aren’t idiomatic in go as they can lead to spaghetti code. Global error handling isn’t idiomatic also and not equivalent from C to Go.

4. Panic behavior in Go isn't similar to the `error` function in the GNU library utilized in the C code snippet; Go's panic function will stop the normal execution of the current goroutine instantly. 

5. Errno is used in C code, but typically Go functions return error values that can be more sophisticated and carry more complex information.

6. Go does not use pointer type or syntax for strings where C code might use `char*`. That necessitates the conversion from
pointer type argument to standard type version within Go.