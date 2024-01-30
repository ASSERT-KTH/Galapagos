To maintain the signature of the function in Go, we need to assert that the argument "buf" is a slice of bytes []byte and also ensure it remains non-nil just like the (void * const buf) in C.

go
import (
  "crypto/rand"
  "io"
)

func randombytes_buf(buf []byte, size uint) {
  if size > 0 {
    if _, err := io.ReadFull(rand.Reader, buf[:size]); err != nil {
      panic(err) // For simplicity we panic on error, modify to handle properly
    }
  }
}

A couple of noteworthy points, Go doesn't support function overloading or default arguments. The random number generation points to a global in crypto/rand which relies on a secure source of random numbers provided by the OS. 
Errors are also part of the function, 'randombytes_buf' will panic and halt execution if there is a problem creating enough randomness, appropriate error catching and handling in line with your application's requirements should be added.