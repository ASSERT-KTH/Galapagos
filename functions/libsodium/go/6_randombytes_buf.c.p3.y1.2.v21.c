The function's implementation will need changes because Go does not support class or instance methods like C does. Instead, functions are defined in a package. Additionally, if `implementation` is an external function object containing multiple algorithms it will require an interface or an argument specifying the specific, named cryptographic algorithm to use. If the original C code received a previously defined `implementation` object with a specified algorithm, use that information to construct an appropriate, idiomatic, Go function: 

go
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
 

Here, the functionality of `statement -> implementation->buf(buf, size)` has been replaced by Go's `crypto/rand` package to provide high-quality random bytes, and Go's `io.ReadFull(rand.Reader, buf[:size])` to populate the buffer. Note that this defaults to a specific cryptographic algorithm based on Go's implemented `crypto/rand` package.