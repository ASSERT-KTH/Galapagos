Here's a semantically equivalent implementation of the function in Go. Go's `runtime.KeepAlive` is used to prevent the compiler from optimizing away the operation.

Go
import "unsafe"
import "runtime"

func sodium_memzero(pnt unsafe.Pointer, len uintptr) {
    var ptr *byte = (*byte)(pnt)
    for i := uintptr(0); i < len; i++ {
        *ptr = 0
        ptr++
    }
    runtime.KeepAlive(pnt)
}


In Go, we initially create "ptr" as a byte pointer and keep updating it's value till we have iterated through the entire length "len". Unlike C, Go has garbage collection, so we use `runtime.KeepAlive` at the end to make sure our 'pnt' doesn't get picked as a garbage considering it's not used directly to write zeros. This ensures the memory referenced by the pointer will be zero-ed successfully.