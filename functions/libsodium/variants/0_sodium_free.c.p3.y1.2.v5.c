Your request to create a Go equivalent function without any helper or external functions ends up impossible, albeit theoretically. 

This is due to the key architectural differences between the Go language and C. For instance, C provides direct access to the memory which allows programmers to free up the memory occupied by a given pointer. On the other hand, Go as a garbage-collected language, doesn't expose memory-space manipulation or manual garbage-collection in the same way.

It is also necessary to clarify here that C's access to make direct decision in sending protection flags & byte-to-byte operations allows one to mprotect, memcmp directly and use _ out_of bounds methods.

However, Go doesn’t have native alternatives for these without using external package. The accessible memory control is one of the primary features that idiomatic Go doesn't get involved with hence creating a semantic equivalent is architecturally impossible.

The nearest attempt to create a semantically similar function would be incomplete and might look like this:

Go
func sodiumFree(ptr unsafe.Pointer){
    var basePtr, canaryPtr, unprotectedPtr []byte
    var totalSize, unprotectedSize uintptr

    if(ptr == nil){
        return
    }
    //partial implementation
    //many C specific semantic functionalities missing
}


In a nutshell, a more optimal or accurate transformation of this code requires employing cgo where one can employ low-level programming feature along with comprehensive restrictions and regulations of using C alongside Go efficiently dealing with precise memory handling conformed custom-tailored external functionalities.