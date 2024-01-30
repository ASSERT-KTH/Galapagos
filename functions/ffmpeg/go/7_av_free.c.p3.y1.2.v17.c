In Go, there isn't native support for conditional compilation nor a way to natively create an equivalent function due to the difference in memory management between C and Go. 

However, a rough equivalent, that aligns with Go's memory management system, would be:

go
func av_free(ptr *interface{}) {
    ptr = nil
}


Please note that unlike manual memory management in C including `_aligned_free()` and `free()`. In Go, memory is automatically safely manipulated using garbage collector. This assignment to null serves to facilitate the garbage collection. 

The Go garbage collector is going to free memory when GC decides internally it is safe to do so and there isn't a direct equivalant `_aligned_free()` or `free()`. A type `*interface{}` is used here because Go is strictly typed and does not have a `void*` equivalent. Any type can be set to it due to the empty interface.