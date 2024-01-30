The Go programming language does not allow you to directly manipulate memory, thus 'malloc' or 'memset' does not have an equivalent operation. However, the following can be considered semantically equivalent with respect to allocating memory to a slice of bytes array and filling it with a pseudo garbage value.

Go
import "bytes"

const GARBAGE_VALUE byte = 0xFF // Substitute appropriate "garbage" value

func sodiumMalloc(size int) []byte {
    if size <= 0 {
        return nil
    }
    slice := make([]byte, size)
    bytes.Fill(slice, GARBAGE_VALUE)
    return slice
}

In the above code, we are creating a 'byte slice'. The inbuilt `make` function allocates a zero-filled array of the given size and returns a slice that refers to it. The size becomes the length and capacity of the slice. Subsequently, the `bytes.Fill` function is called, which writes the given byte value to each element of the slice.