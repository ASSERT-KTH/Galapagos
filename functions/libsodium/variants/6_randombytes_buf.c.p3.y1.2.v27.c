Go does not support method overriding or direct pointers manipulation like C does, hence, callback operations can not be implemented exactly like in your example. 

However, the closest idiomatic way for doing it in Go could be to define a custom type, that will represent the `implementation` and provide its `Buf` method.

go
type BytesImp interface {
    Buf(buf []byte) error
}

func RandomBytesBuf(buf []byte, size int, implementation BytesImp) {
    if size > 0 {
        implementation.Buf(buf[:size])
    }
}

Note also that Go does not support constants of type `Void`. Instead, it uses slices. Data from `rand.Reader`, which represents a cryptographically secure pseudorandom number generator (stream of random bytes suitable for cryptographic use) will only be populated on a buffer when `Buf` implemented by `BytesImp` being called.