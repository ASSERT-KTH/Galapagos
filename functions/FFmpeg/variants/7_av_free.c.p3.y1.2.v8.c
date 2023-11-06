In Go, there's no concept of aligned and regular free operations. Once a variable goes out of scope, its memory is handled by Go's garbage collector. Hence there's absolutely no way to manually free memory. So it's not possble to define an exact equivalent function in Go. However, if it's a must to set the reference to nil, that could be accomplished with interfaces in way similar to this:

go
func avFree(ptr interface{}) {
    switch v := ptr.(type) {
    case *int:
        *v = 0
    case *float64:
        *v = 0
    case *string:
        *v = ""
    // add more cases if needed
    }
}

This will set the pointed object to its zero value but it won't free up the memory as in C. It's important to remember that all variables in Go are initialized to their zero value. And setting an object to its zero value will not immediately free up its memory; it's still up to garbage collector to reclaim that memory.