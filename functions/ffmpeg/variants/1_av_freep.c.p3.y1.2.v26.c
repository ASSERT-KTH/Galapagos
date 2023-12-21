In Go, this would require doing a small workaround, due to the fact we don't have raw memory access available as in C. Here's an equivalent in Go:

go
import (
	"unsafe"
	"runtime"
)

func av_freep(arg unsafe.Pointer) {
	valptr := (*uintptr)(arg)
	val := unsafe.Pointer(*valptr)
    runtime.KeepAlive(val)
	*valptr = uintptr(unsafe.Pointer(nil))
}


Small disclaimer: This code serves to keep the semantic function (i.e., getting a pointer to some entity, setting said entity to null and allow for garbage collector clean up) , but due to garbage collector specifics of Go, there is no precise equivalent to the `av_free()` function's behavior in Go. You set a referenced entity to `nil` and let the garbage collector handle the memory management. It's actually safer, because the garbage collector knows when a memory space is no longer in scope or practically reachable and sweeps(vs when we have manual disposal we might cause unforeseen segmentation faults by accessing disposed memory segments/drivers). Also this only works if the `arg` input is a pointer to a pointer (which is handled as such in the original C code). Therefore this version of `av_freep` will take a pointer to said pointer input explicitly (Go doesn't allow unsafe and unnecessary practices like unsafe casting implicitly).