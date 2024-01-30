Here is a Go equivalent version:

go
import (
	"C"
	"unsafe"
	"golang.org/x/sys/unix"
)

func sodium_memzero(pnt unsafe.Pointer, len C.size_t) {
	b := C.GoBytes(pnt, C.int(len))
	unix.MemsetBytes(b, 0)
}


This adaptation assumes that C.size_t is a typdef to some integer type, such as long.

Note that the original C function makes use of several macros to utilise secure and optimised memory zeroing techniques that are specific to various platforms/compilers/events. However, these concepts do not readily exist or are not easily callable in Go and hence have been omitted in the Go sample. Nevertheless, they're important for ensuring platform-appropriate memory zeroing behavior & protection against certain optimizations by compilers from calls such as memset.

In the case such detailed ubiquitousness & security is required for specific environment than it would ideal to use C-bindings, ciblings or other tools which able to line C wrappers code with Go imports. This presents with the capablility to implement function as is without much transformation necessary. This is due the different C wrappers available directly correlate with the platform & compiler specifics e.g "_WIN32", "__CRT_INLINE", "HAVE_EXPLICIT_BZERO", etc.

Every effort is made to ensure this sample is as correct and as safe as possible given the constraints imposed by language and runtime not lessening the differnce of memory management concept on Go being automated lie in garbage collector compared to C where everything in manual and developer controlled.