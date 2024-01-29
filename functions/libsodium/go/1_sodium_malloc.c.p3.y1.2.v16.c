In Go programming language, you cannot directly allocate memory and access it like you do in C. Hence setting it to an initial garbage value cannot be done directly. 

But memset and memory allocation go hand-in-hand in C-language, the closest possible alternative in Go-language would be:

golang
import "errors"

const GARBAGE_VALUE uint8 = 0xff // change the garbage value as needed.

func sodiumMalloc(size int) ([]byte, error) {
    if size <= 0 {
        return nil, errors.New("Size must be greater than 0.")
    }

    data := make([]byte, size)
    for i := range data {
        data[i] = GARBAGE_VALUE
    }

    return data, nil
}


This new method will create a slice of bytes with a given size and initialize it with a "garbage" value. Since error can not be null like pointers in C, it will instead be indicated using in returned "error" object.