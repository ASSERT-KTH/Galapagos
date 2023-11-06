Unfortunately, Go does not support direct memory-level operations like those in languages such as C or C++. Writing data into a raw memory adress, passed as an argument, cannot be implemented directly because direct memory operations rely on pointer manipulations which are highly restricted in Go for safety purposes. However, we can create similar functionality using Go's idiomatic way:

go
import "crypto/rand"

func RandomBytesBuf(buf []byte) {
    if len(buf) > 0 {
        _, err := rand.Read(buf)
        if err != nil {
            panic(err) // choose appropriate error handling here
        }
    }
}


In this example, `buf` is a slice of bytes, you can write to its contents. The `crypto/rand` package `Read` function reads from cryptography secure random source, populating `buf` with random data. As with Go's standard slice manipulation, anything you do to `buf` inside the function is visible to callers, similar to the original C function's direct memory manipulation.

A panic is used where an error occurs reading random data, replace it with other error-handling code as it suits your application needs.