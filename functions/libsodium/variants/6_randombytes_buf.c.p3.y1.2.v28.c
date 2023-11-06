It's challenging to convert this function exactly in Go because Go doesn't have a clear equivalent for void pointers and doesn't use the notion of constant variables like `const` in C. Here I am assuming `randombytes_init_if_needed()` and `implementation->buf(buf, size)` is generating random bytes and filling up `buf`. Below creates a byte slice of `<size>` length and fills it with cryptographically secure random numbers in Go.

Go
import (
    "crypto/rand"
    "fmt"
    "io"
)

func randombytesBuf(buf *[]byte, size uint) {
    *buf = make([]byte, size)
    if size > 0 {
        _, err := io.ReadFull(rand.Reader, *buf)
        if err != nil {
            fmt.Println(err)
        }
    }
}


Here `[]byte` is used as a type in Go that works similarly to `void*` in C. It allocates a number of bytes specified by `size` and tries to fill the buffer with cryptographically secure random numbers. The error is printed when no random numbers can be made.

Note: The original function didn't specify what to do in cases of failure so error checking might differ. It's not clear how original C function was implementing the functionality.