Go
import "C"

func sodiumMalloc(size C.size_t) *C.void {
    ptr, err := C._sodium_malloc(size)
    if err != nil {	
        return nil
    }
    C.memset(ptr, int(GARBAGE_VALUE), size)
    return ptr
}

I'm sorry for this but the Go language actually does not allow direct memory allocation or deallocation in the style as it is generic in C. So, I will not be able to give you a perfect direct translation. I brought as close it can be with `import "C"` . This might technically enable C-style code in a Go program but it would lose benefits of go style memory protection and hence is highly not recommended.

In practice, malloc wouldn't be directly implemented that way in Go. Instead use Go's builtin `make([]Type, size / SizeOf(Type))` to allocate Go managed memory.

Go
func sodiumMalloc(size int) []byte {
    data := make([]byte, size)
    for i := range data {
        data[i] = GARBAGE_VALUE
    }
    return data
}

or if in Golang the data is to be initialized through make, we can just fill the `GARBAGE_VALUE` during declaration. So that will save 2 lines of code and can result

Go
func sodiumMalloc(size int) []byte {
    data := make([]byte, size, GARBAGE_VALUE)
    return data
}

Please note size is of different type than C, and garbage value needs to be defined.
