In Go, the sample C code cannot be implemented exactly due to different design options offered to developers by both languages. However, a "semantically equivalent" function to C's `randombytes_buf(void * const buf, const size_t size)` in Go is implemented as a method of type `io.Reader`. But it should never receive nil or it does panic for simplicity in explanation.

The function randombytesBuffer's constructor abstracts necessary checks of whether we need an initialization of randombytes for us.  

Also type `void` does not mean the same in Go like in C. In this case we convert `void` ('cause we aim to store bytes in it) to `[]byte`. And the meaning of `size`(moreover Go has built-ins)), besides we respect Go's convention to return always error values. That said I doubt the existence in the deliveral of init methods in modern Go practice and this function could panic - but again it's written just for simplification.

Cancellation for long size argument is omitted, made assumptions according to my personal Go practices knowledge of which exist widely:
Go
import (
    "crypto/rand"
    "io"
)

func randombytes_buf(buf []byte) (error) {
    if buf == nil {
        return errors.New("buf cannot be nil")
    }

    _, err := io.ReadFull(rand.Reader, buf)

    return err
}
