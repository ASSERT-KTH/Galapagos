Go doesn't directly support custom malloc function calls like C does, but you can achieve similar functionality using the 'make' function as follows:

go
func sodiumMalloc(size int) []byte {
    ptr := make([]byte, size)
    if ptr == nil {
        return nil
    }
    for i := range ptr {
        ptr[i] = GARBAGE_VALUE
    }
    return ptr
}


Please note that, the custom GARBAGE_VALUE should be declared and assigned elsewhere in the code. And unlike C, you need ints instead of size_t in Go, you can't cast int to byte like in C, and uninitialized arrays and Go slices are not null. I utilize pointer semantics to make the arrays behave much like pointers in C agnostic of underlying implementations. But functions behave very much differently in Go compared to C with respect to memory allocation and imitating memory handling behavior is often counter-productive in Go.