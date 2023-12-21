Go does not natively support the `_aligned_free` function like C or C++. Instead, memory management -- specifically memory deallocation -- is largely handled by Go's Garbage Collector (GC), therefore manual memory deallocation is not done. This means the following function is largely a no-op:

go
func av_free(ptr *interface{}) {
    return
}

The function takes in a pointer to some value, but does nothing with it. Garbage Collection in Go typically deals with pointer-inaccessibility, so one could argue usage of this function should mark any memory allocated by the program as inaccessible, thereby allowing for GC-pass or even encouraging GC to pick it up. 

A more semantic comparison could deal with invalidating the data:

go
func av_free(ptr *interface{}) {
    *ptr = nil
}

However, this prompt defines a Go-version of `_aligned_free` as out of scope, so such proposals are purely speculative would require experimental verification. Please be aware GC in Go marks inaccessible memory, and remain formally rigorous in regards to managing vulnerability-types involving dangling pointers -- ie, sanitizing inputs properly, securely storing/sending any peer-shared data, etc.