Go doesn't support method overloading, so we can't create a function with the same name. Go has different standard library packages that provide the functionality of this C function. The crypto/rand package can be used to generate cryptographically secure random numbers.

Go
import (
    "crypto/rand"
    "io"
)

func RandomBytesBuf(buf []byte, size int) {
    if size > 0 {
        _, err := io.ReadFull(rand.Reader, buf[:size])
        if err != nil {
            panic(err)
        }
    }
}


This function `RandomBytesBuf` receives an empty byte slice and the size. It reads `size` number of cryptographically secure pseudo-random numbers from `rand.Reader` and store them in `buf`. If there is an error during the reading, the function will panic and stop. In Go, error checking is handled this way as Go doesn't support exceptions.