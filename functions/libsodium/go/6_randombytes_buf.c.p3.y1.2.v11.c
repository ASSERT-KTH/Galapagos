It's not possible to do a direct and exactly equivalent conversion of this function from C to Go due to differences between the languages. Go does not allow defining new function implementation at runtime unlike C - the `implementation->buf(buf, size)` part. 

Instead in go, we make use of interfaces if we need some functionality similar to that. But in this context because Go doesn't allow for overriding inherent system functionality like random byte creation, we are bound to use the provided functionality in the "crypto/rand" package.
  
Here's a way to write a corresponding 'randomBytesBuf' function in Go that would fill variable `buf` with securely generated random bytes of length `size` hopefully accomplishing a similar goal depending upon context.

golang
import (
    "crypto/rand"
    "log"
)

func randomBytesBuf(buf []byte) {
    _, err := rand.Read(buf)
    if err != nil {
    	log.Fatalln(err.Error()) // halts if unsuccessful
    }
}

This will take as input 'buf' slice and fill it with 'secure' random bytes generated using crypto rand package provided by Go stdlib. Note that security of these generated random bytes may not be equivalent to your version of random in the C code. 

A very important detail worth noting :
We're directly manipulating `buf` here. A slice as passed is really a struct with a pointer and doesn't need to have a pointer receiver to modify that actual data of the slice or array it's based on, unlike C where we have to pass explicitly types alike by reference when we want to modify them inside called function's scope.