Unfortunately, this task cannot be done exactly as you requested. The specific problem is the function's signature. In C, you can directly manipulate a given buffer of bytes based on the pointer, whereas in Go, unless you're dealing with slices, manipulations happen on a copy of the input. Furthermore, when you call a function with slice as an argument, it keeps the reference to the original value. So the best we can do is to use slices as the equivalent. 

Another issue is interacting with an "implementation" equivalent that has buf method. In Go, it is mostly appropriate to deal with such a high level behavior via interfaces, but since you asked to avoid adding auxiliary helpers and considering the context, the translation will resemble something like this:

go
import "crypto/rand"

func RandomBytesBuf(buf []byte) {
    if len(buf) > 0 {
        _, err := rand.Read(buf)
        if err != nil {
            panic(err)
        }
    }
}


Here, I matched "randombytes_init_if_needed" with crypto/rand.Read. Not seeing an exact definition of the C version, I'm assuming that Go's built-in method from the crypto/rand package is equivalent. In production-level code, you wouldn't use "panic", and you'd write purposeful error handling code at that point - the translation might otherwise result different outputs.