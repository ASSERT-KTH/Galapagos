Unfortunately, Go language does not directly support the same equivalent for this C code. It has built-in GC(Garbage collector) which handles critical memory related tasks such as memory allocation and de-allocation. Therefore any equivalent of explicit memory management through code as done using `free()` or `_aligned_free()` is pointless in Go. But to free up the variable for garbage collection you can make the variable point to `nil`. Still remember Go gatbage collector will decide when to free the memory.

Go
func av_free(ptr *interface{}) {
    *ptr = nil
}

In Go, one doesn't need to worry about allocating or deallocating memory like in C. The Go runtime takes care of maintaining memory so you, the developer doesn't have to. When you are no longer holding any active reference to a piece of memory, it gets automatically marked for garbage collection and is freed at a time that the runtime deems opportune. However, if you have secured a block of memory and need to indicate that it’s no longer in use so could be ready for garbage collection at any time, you typically set the reference to nil.

My advice would be not to try to translate that function at all. Go's memory model is totally different than C's, control over each allocation's lifespan is much better left with Go's garbage collector. 

This statement might help force the Go garbage collector to possibly speed up freeing some memory, but mind you it is not guaranteed: `runtime.GC()`. 

In summary: In Go, all memory releasing strictly depends on Go garbage collector. You can't control the memory as directly as with C.