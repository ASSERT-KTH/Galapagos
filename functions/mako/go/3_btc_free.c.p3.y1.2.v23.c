Here is the Go equivalent of the C function:

go
import (
	"os"
)

func btc_free(ptr *interface{}) {
	if ptr == nil {
		os.Exit(1)
	}

	*ptr = nil
}


It's worth noting that unlike in languages like C, memory management in Go is automatic. The Go runtime takes care of allocating and (most importantly in this case) deallocating memory that an application uses. Therefore, typically you don't need a function that explicitly deallocates memory like `free` does in C. Setting the pointer to `nil` will allow Go's garbage collector to free the memory. However, Go programs may choose to explicitly or implicitly invoke `runtime.GC` method, which synchronously runs a garbage collection and in such scenarios - the definition provided above can be used. It's also the reason as to why the Go version of the provided C function is implemented as it is.