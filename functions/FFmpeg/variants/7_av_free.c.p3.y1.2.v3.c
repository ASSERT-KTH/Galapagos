Unfortunately, you can't directly translate this C function into Go. Go's garbage collector handles memory allocation and deallocation automatically, thus it lacks a built-in "free" function.

Therefore, we don't deal with explicit deallocation or "free" function equivalents in Go. 

However, to so it doesn’t hold onto its memory for the entire lifetime of the program.We show you can release possible pointer related references to allow Go runtime (garbage collector) to free memory. 

Only workaround could be setting up pointer to nil, to suggest Go garbage collection that underlying memory could be collected:

go
func avFree(ptr *interface{}) {
    *ptr = nil
}


But please note, this is very different then memory freeing in C-style.+