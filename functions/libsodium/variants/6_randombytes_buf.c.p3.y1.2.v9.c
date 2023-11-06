In Go, we unfortunately cannot keep the exact function signature because of incompatible types (void * in C vs interface {} in Go) and different language paradigms. That said we can write a function that accepts a byte slice reference as similar as possible in semantics:

go
import "crypto/rand"

func randombytes_buf(buf *[]byte, size int) { 
    if size > 0 {
        *buf = make([]byte, size)
        _, err := rand.Read(*buf)
        if err != nil {
            panic(err)  // or handle it in another way
        }
    }
}


Important notes:
- In Go, arrays and slices are already reference types. Here we use *[]byte to actually change the reference to newly allocated memory area where we store the random bytes.
- We replace "randombytes_init_if_needed" and "implementation->buf(buf, size)" from Sodium library with directly reading values from crypto/rand package.