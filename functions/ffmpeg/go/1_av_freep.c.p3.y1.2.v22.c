Unfortunately, it is not possible to create an equivalent version of the given C function in Go, as Go does not support pointer arithmetic or unsafe memory manipulations in the same way C does. 

Furthermore, Go has a built-in garbage collector which automatically frees memory that is not referenced anymore.

This feature invalidates the need for functions similar to av_freep, which in C is used for deallocating dynamically allocated memory. 

So normally in Go this behavior wouldn't be advisable nor required. Here is a simple illustration of creating and setting a pointer as nil

go
func av_freep(arg *interface{}) {
        *arg = nil
}
