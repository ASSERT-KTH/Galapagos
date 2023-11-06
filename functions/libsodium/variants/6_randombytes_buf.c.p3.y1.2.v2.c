The requested function doesn't exist directly in Go, since the Go environment doesn't utilize a global implementation variable nor require explicit initialization like the C-based libsodium framework. Nonetheless, the idiomatic way to generate a specified quantity of random bytes in Go would involve using the crypto/rand package's Read function.

Here's how the equivalent "randombytes_buf" functionality could be written in Go :

Go
import "crypto/rand"

func RandomBytesBuf(buf []byte) {
    _, err := rand.Read(buf)
    if err != nil {
        panic(err)
    }
}

This Go function takes a byte slice, buf, as an argument, and fills it with cryptographic random numbers. If ok is false there is a problem when reading a slice. Please note that error handling in Go is frequently explicit, and it's common to handle potential errors right in-place, rather than initializing some global state or mechanism (like randombytes_init_if_needed()) if an error is casually occurred. Also, we used the capitalized name (RandomBytesBuf) because Go uses the capitalization of the first letter of a function to determine its visibility. In this case, a capitalized name means that the function should be available/exported publicly.