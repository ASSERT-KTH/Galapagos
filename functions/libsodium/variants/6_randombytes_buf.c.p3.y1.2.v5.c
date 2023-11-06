In Go, the equivalent implementation using the "crypto/rand" package would be like the following. Since Go doesn't have a void data type and does not allow direct manipulations of memory addresses, we have to use a slice of bytes as the buffer.

Go
import (
    "crypto/rand"
    "io"
)

func RandomBytesBuf(buf []byte, size int) {
    if size > 0 {
        _, err := rand.Read(buf[:size])
        if err != nil {
            panic(err) // or handle it in a way you find appropriate
        }
    }
}


Please note that Go's built-in error handling pattern is utilized here, which is a difference comparing with original C function. If "rand.Read()" fails then the error can be propagated further towards the main function, which can decide whether to handle it or panic and terminate the program. Errors like these are unusual, possibly caused by a failure in the underlying operating system or hardware, and they aren't typically ones you can handle gracefully. So it would be ok to use convenient "panic()" function here in case of error. 

Do not forget to slice the byte buffer just to required size with buf[:size]. This will ensure that you do not read more bytes than is available in the buffer triggering an out of range runtime error. For a large enough buffer (size variable), you may need to add extra checks before slicing a byte buffer in this way.