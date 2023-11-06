Unfortunately, Go doesn't contain the exact equivalent of C's sodium_malloc function, but we might attempt to write similar functionality in Go:

go
import "runtime"

const GARBAGE_VALUE = 0

func SodiumMalloc(size int) []byte {
    if size <= 0 {
        return nil
    }

    b := make([]byte, size)
    for i := 0; i < len(b); i++ {
        b[i] = GARBAGE_VALUE
    }

    runtime.KeepAlive(b)
    return b
}


This uses Go's built-in `make` function to try and create a byte slice of the provided size, then it fills this byte slices with the GARBAGE_VALUE (0 in this case, adjust it according to what value is meant to represent "garbage"). If an allocation fails (for example, due to a lack of sufficient memory), Go will panic automatically, so there's no explicit error checking required. Finally, `KeepAlive` extends the life of `b` to the end of the function (to suppress potential in-opportunistic recovery while still in use).