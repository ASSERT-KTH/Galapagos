In Go, we don't have preprocessor directives equivalent to `#if` or `#endif` and the memory allocation/freed mechanism is automatically achieved with inbuilt garbage collector. Thus, the exact equivalent code for disposing memory like the provided C function cannot be represented in Go as it automatically handles "freeing" of memory.

However, here is a rather simplified/no-op version of your function in Go:

go
func avFree(ptr *int) {
   // No body because Go automatically handles memory allocation via garbage collector.
}


Basically, we don't need to free pointers in Go. The runtime takes care of this via garbage collection. And _aligned_malloc is specific to systems that require memory alignment, so there isn't a similar thing in Go either.