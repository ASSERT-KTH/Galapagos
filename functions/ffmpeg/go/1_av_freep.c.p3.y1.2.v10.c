Although point manipulations like this generally not recommended in Go, we can simulate similar functionality using the "unsafe" package. Here is how it can be done. Please make sure before using unsafes types of method because its break the Go safety behavior, be advised to check if there alternative and safer ways to reach the target. 

go
import (
    "unsafe"
)

type UnsafePointer unsafe.Pointer

type av struct {
    ptr UnsafePointer
}

func av_free(a *av) {
     // here we will implement avfree operation
}

func av_freep(v *UnsafePointer) {

    val := *v
    *v = nil

    av_free((*av)(unsafe.Pointer(&val)))
}



Please note that this only resembles similarity in FFI Wrapper. Go has automatic garbage collection that does not require manual memory management like C, you'd normally don't see function like `av_freep`.
If you meant to create a way to nullify the pointers in Go, you'd get closest by using simply `*v = nil`, provided `v` is not a Pointer but `Pointer to Pointer` as memory allocation can be removed my inline command as well i,e `v=nil`.