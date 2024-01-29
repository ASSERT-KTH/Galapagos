go
func ldbBufferClear(z *LdbBuffer) {
    if z.alloc > 0 {
        free(z.data)
    }

    z.data = nil
    z.size = 0
    z.alloc = 0
}


Please note that:
1) In Go, you would typically use garbage collection to free up memory rather than call a `free` method.
2) I assumed that `LdbBuffer` struct in Go has the same fields and their types as in C version. This would look something like this:
go
type LdbBuffer struct {
	data  *SomeType
	size  int
	alloc int
}

3) The `SomeType` needs to be replaced with the respective appropriate data type.
4) It's impossible in pure Go to ensure exactly the same behaviour that C free function does. It's noteworthy that the area pointed to by ptr is deallocated (i.e., made available for further allocation) by free(), but not erased. In other words, releasing the memory doesn't change the value of data. If some kind of memory clean up was required you would write zero value or your initial values on data again before setting z.data to nil but generally not needed with garbage collection.
5) The `free()` is part of Go's `unsafe` package and calls C.free under the hood. The `unsafe` package is not recommended for most Go users due to compatibility issues on some systems and potential for introducing hard-to-find bugs. Function ldbBufferClear here doesn't have explicit call to C.free, add it inline if it's necessary for your particular use case or build with Go's cgo:
go 
/*
#cgo LDFLAGS: `${srctree}/bazel-out/host/bin/external/go_sdk/pkg/tool/linux_amd64/cgo -objdir “[replace with your path}” -importpath {package name here} -src="[replace with your actual cgo code]"
#include <stdlib.h>
*/
import "C"

C.free(unsafe.Pointer(z.data))
