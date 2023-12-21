Go does not require manually freeing memory, as it includes a built-in garbage collector that automatically retrieves unused memory. Therefore, a "freeing" function like you described doesn't need - nor should it exist - within the context of Go.

However, for illustration purposes, we can show a function with memory management in Go by marking the pointer as `nil`. Note that memory actually collected by garbage collector when it's no longer reachable. 

So semantically closest we can make Go function to your C function is:

Go
func av_free(ptr *interface{}) {
    *ptr = nil
}


Understand that this action isn't equal to `free()` or `_aligned_free()` in C. This just takes away the reference to memory object, but does not guarantee direct memory freeing. The Go garbage collector chooses when to "free" the memory. Specifically, it will free this object when there are no more references to it - and not necessarily when this function is called.