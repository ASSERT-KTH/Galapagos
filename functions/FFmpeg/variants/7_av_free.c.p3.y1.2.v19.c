Go does not have a preprocessor like C to conditionally compile chunks of code. Thus, checking for system configurations like HAVE_ALIGNED_MALLOC manually and providing two versions of the function is unavoidable.

Additionally, memory management in Go is garbage collected, meaning you don’t need to manually free memory like in C. There is no direct equivalent to free in Go,

However, you can set the memory to nil to make it eligible for garbage collection, which is as close as you can get with a semantically equivalent version of av_free in Go:

go
func av_free(ptr *interface{}) {
    *ptr = nil 
}


You would call this function with a pointer to the variable you want to 'free'. If that variable is the only usage of that underlying data, it will be cleaned up by the garbage collector sometime after you call av_free.

Do note that Go strongly discourages meddling directly with memory management and this kind of tricks should really be the exception and not the norm due to more notorious consequences on runtime performance.