Assuming that `ldb_buffer_t` in C is similar to a custom type, `LDBBuffer` in Go, it could look like this:

go
type LDBBuffer struct {
    data  []byte
    size  int
    alloc int
}

func (z *LDBBuffer) Clear() {
    if z.alloc > 0 {
        z.data = nil
    }

    z.size = 0
    z.alloc = 0
}


Please note a few things:

- Because Go is garbage collected, there isn't a direct need for `ldb_free(z->data);` alike in a C based implementation.
- Always think about zero-values while implementing. For example, the zero value of a slice (`[]byte`) is `nil`, which is being used.
- Go doesn't support function overloading, however methods can be used to achieve some pattern of function overloading. This implementation makes use of method receiver `(z *LDBBuffer)` for `Clear()`.
- Go does not have a `->` operator like C and the semantics are written using a '.'
- In Go, it's conventional to name the receiver of a method `s`, `v`, `p`, etc. But here, `z` is suitable, too. So, no need to worry.
- Lastly, function/ method names in Go should be captialized when you want them to be exported.