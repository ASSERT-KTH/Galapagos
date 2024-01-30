In Go, we don't have pointers to pointers like in C and hence we need to modify the function interface to use forward reference. An alternate approach in Go would look like:

go
func av_freep(arg **interface{}) {
	*arg = nil
	// assumed that `av_free` is present according to given C code, it should be implemented separately, referencing to specific implementation
	// av_free(arg)
}


The key idea behind the C code seems to be nullifying the given pointer and freeing the underlying memory that it points to. But Go abstracts the control over the memory management. Native Go doesn't give us access to something like av_free. That is handled for us by the Go's garbage collector. You indicate that memory can be freed by setting your references to nil. Once the Go runtime sees that there are no references to object, it will clean it up.