go
import (
	"log"
	"runtime"
)

func LdbMalloc(size uintptr) unsafe.Pointer {
	ptr := C.malloc(C.size_t(size))
	if ptr == nil {
		buf := make([]byte, 1<<20)
		stackLen := runtime.Stack(buf, true)
		log.Fatalf("Out of memory (tried to allocate %v)\nStack Trace:\n%s", size, buf[:stackLen])
	}
	return ptr
}

The Go function 'LdbMalloc' uses the 'C.malloc' function to allocate a chunk of memory of 'size'. It checks whether the pointer to the allocated space is 'nil', in which case it creates a dump of the stack trace and terminates the program.
The Go code does not exactly achieve what the original function ‘ldb_malloc’ did in terms of its response which chose heap memory management errors; in that C just immediately terminates while Go chooses to print a stack trace so that the reason for termination could be diagnosed. The Goroutine-friendly ‘runtime.Stack’ function is employed in this code for this purpose, creating a 1 Megabyte chunk of memory to contain it. Typically 1 Megabytes would be overkill, but allocation amounts aren't provided by the environment to calculate how small the slice can be, while compromising on details of the stack trace would be unnecessary.