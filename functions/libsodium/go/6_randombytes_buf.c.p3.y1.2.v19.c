It's important to note that C and Go handle certain things very differently, so a direct conversion isn't possible. But we do our best.

In Go, we wouldn't bind an implementation of randomness at runtime as it seems the C code is indicating. However, the general sequence would be a check to initialize a required thing (if needed) and some kind of action using an interface. The Go standard library "crypto/rand" package can serve as our randomness generator. 

Here is a rough equivalent code in Go. But keep in mind, this is a rough equivalent and it would be doing initialization and randomness generation quite differently in good, practical, idiomatic Go code:

go
import "crypto/rand"

func randomBytesBuf(buf *[]byte, size int) {
    // The init "if needed" equivalent doesn't really transfer to Go from the C code.
    // For instance below code panics if crypto/rand package failed to initialize at the startup in Go.

    if size > 0 {
        *buf = make([]byte, size)
        _, err := rand.Read(*buf)
        if err != nil {
            panic(err)  // This panic is an equivalent of error which must not be ignored in Go applications.
        }
    }
}


Caution:
In the given C function, it dynamically selects a function at runtime (based on the "implementation" pointer) to actually perform the byte population.

The Go equivalent provided does not have this behavior. It will always use the "crypto/rand" package's Read method and doesn't provide a way to plug in different random byte generation implementations. This is a notable trade-off, and if this functionality is required, we could consider using interfaces in Go.