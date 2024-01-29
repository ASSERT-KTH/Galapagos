Unfortunately, returning a "NULL" in Go is not as straightforward. Instead of returning a "NULL", the following solution will check for an equivalent memory allocation failure in Go and panic, similar to how out of memory situations in Go runtime are by default.

Go
import "unsafe"

type Size uintptr

func AvCalloc(nmemb Size, size Size) unsafe.Pointer {
    if Size(MaxInt/size) < nmemb {
        panic("memory overflow")
    }
    
    ptr := C.calloc(nmemb, size)
    if ptr == nil {
        panic("unable to allocate memory")
    }
    
    return ptr
}


Please note, Go does not support unchecked array allocation (specified by a parameter) which exists in lower-level languages such as C. If used in overall safety-critical contexts, those calls need to be narrowly checked one-by-one per allocation or use third-party libraries for that purpose.

This question may violate normal Go programming practices, as unsafe.Pointer is used, but if you decide to use it, do so exceedingly sparingly and ensuring it was indeed necessary to do. If you need to convert to Go from unsafe calls made in C in large volume, it is advisible to reconsider the design decisions that led to this course instead of doing it anyway.