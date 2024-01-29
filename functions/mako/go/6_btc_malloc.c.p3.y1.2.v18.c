go
import (
    "os"
    "unsafe"
)

func btcMalloc(size uintptr) unsafe.Pointer {
    ptr, err := os.NewHandle(size)

    if err != nil {
        panic(err)
    }

    return unsafe.Pointer(ptr)
}

Regrettably, this is as close as it gets. Go strongly discourages usage of 'malloc' equivalencies or attempting to work around the garbage collector, and also there's no direct translation of abort(). The package: "os", function: "NewHandle" provides the closest similarity, allowing the allocation of a bloc of memory of a certain size else panic with an 'out of memory error', simulating a direct abortion of the program. Forcing unsafe.Pointer on it at least gives it a similar output to C's 'malloc' function.
If you expected to get a []byte or something of the like keep in mind that it wouldn’t be particularly good Go code. Developers are supposed to reason at above the C level. This is particularly proven point with the presence of type 'unsafe.Pointer'. Typically its usage is discourage in Go, yet it's virtually the only type that has some semblance to void* remaining slightly below Go’s normally minimum-abstraction layer. Despite such semblances, most admit it doesn’t really resemble malloc’s void* much at all in terms of interaction so whatever it is, it can be pretty misleading to interpret it as a malloc equivalent. Additionally C's 'abort()' doesn't match perfectly well with Go’s built-in 'panic(err)'. Of course 'err' should be replaced with an appropriate error if you make sure there’s context, but none is necessarily necessary. A good to-consider replacement is like its below:
go
    if err != nil {
        panic("allocation error or out of memory error")
    }

This allows for design of emergency circumstances enforced by inappropriate execution.