Unfortunately, converting this C function to an exact equivalent in Go isn't directly possible because:

1. Go isn't an object-oriented language that uses class and implementation like C.
2. Go handles error more explicitly.

But you can write a function that essentially performs the same thing by generating a random byte array in initialize it only if the given size > 0 in Go.

Here's a semantic equivalent code :

go
import "crypto/rand"

func randombytes_buf(buf *[]byte, size int) {
  if size > 0 {
    *buf = make([]byte, size)
    _, err := rand.Read(*buf)
    if err != nil {
        panic(err.Error())
    }
  }
}


This function receives a pointer to a byte array and a size. If the size is greater than zero, it populates that byte array with random bytes read from a crypto-strong random source. If an error occurred trying to read from the randomness source, it panics. Otherwise it does nothing (mimics original empty execution when size <= 0).