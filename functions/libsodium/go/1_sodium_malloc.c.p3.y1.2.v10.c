Since Go directly supports error handling, the language doesn't have null values and functions never return null. They rather return an error. Secondly, Go's os package can be used for managing memory allocation. 

Therefore, sodiumMalloc func would look like:

go
import (
    "bytes"
    "os"
)

const GARBAGE_VALUE = byte(0)

func sodiumMalloc(size int) ([]byte, error) {
    ptr := make([]byte, size)
    _, err := os.ReadAtLeast(bytes.NewReader(ptr), bytes.Repeat([]byte{GARBAGE_VALUE}, size), size)
    if err != nil {
        return nil, err
    }
    return ptr, nil
}


Though the main syntax is changed a bit, the semantic meaning is conserved i.e., we try to allocate memory and initialize it with undefined garbage value. Return the pointer if success, else return error. 

As bytes read here impose limit, please make sure to use `readFull(...)` rather than `ReadAtLeast()` when you actually try in real applications for proper initializations.