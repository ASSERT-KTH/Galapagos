Due to Go's approach to error handling and built-in types, we can't exactly replicate the original function in C. Below is a principle expression of the desired functionality with Go.

go
import "bytes"

const GARBAGE_VALUE byte = 'a' // for instance

func sodiumMalloc(size int) []byte {
    if size < 0 {
        return nil
    }
    data := make([]byte, size)
    bytes.Fill(data, GARBAGE_VALUE)
    return data
}


This function will create a slice of bytes of the requested size and fill it with the predetermined "GARBAGE_VALUE". If the provided size is less than 0, the function will return nil.