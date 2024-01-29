Unfortunately, Go doesn't have preprocessor directives or conditional compilation exactly like the C preprocessor has so it's not a completely straightforward translation. We'll also assume that "HAVE_ALIGNED_MALLOC" is intended to represent a platform that requires a special API call to free heap memory allocated with an API for alignment-specific heap memory.

There's no direct one-for-one translation from this C code to Go. The Go language does not natively support the low-level software requirements implied by "HAVE_ALIGNED_MALLOC".

In Go, same memory model for all platforms is used and freeing memory happens automatically, as it has the garbage collector built-in.

But the closes thing to the C free function in Go can be to use maps or pointers and set them to nil after use.

Here is an exemplary simple implementaion:
go
func avFree(param *interface{}) {
    *param = nil
}

By setting *param to nil, we're allowing Go's garbage collector (Go's "free" mechanism) to clean it up and remove it from memory.

Be aware that using this function won't actually free the memory but if there are no more references to the object being point to the garbage collector will deal with it in due time. 

Another precaution you will need exclusive control (read and write access) over the reference to the object and ensure that there are no existing shared references otherwise this will not result in the memory being ready for garbage collection.