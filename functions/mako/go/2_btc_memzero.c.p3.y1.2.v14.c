One thing to note is that C provides more low level operation like controls for memory management (e.g. Zeroing out memory (nullifying memory locations), SecureZeroMemory for windows that ensures the compiler does not identify it as a redundant command and omits zeroing during optimization) that go does not provide.
However, zeroing of slices in Go is much simpler and generally this sort of operation would be uncommon as it handles much of the memory management automatically behind the scenes.

If you had a byte` slice for example and you needed to zero it you can use the built in `copy` function,

For translating the function to GO,

go
func btc_memzero(ptr *[]byte, len int) {
    if len > 0 {
        copy(*ptr, make([]byte, len))
    }
}

This won't be perfect replacement always, as Go and C fundamentally work with memory management differently. Plus nullifying pointers isn't as critical or common in Go as it's garbage collected language compared the manual memory management in C. this particular function focuses on "Secure Memory Zeroing" on executing assembly code. Go is at a higher level and doesn't give you control at that level. However, it is enough for basic memory sobstitution to ZERO in Go.