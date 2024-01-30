Unfortunately, it's not directly possible to create a semantically equivalent function in Go without changing the function's signature and type because Go is strictly typed and does not support unsigned int directly.

We can have a function like this:

Go
func avio_wb32(s *AVIOContext, val uint32) {
    avio_w8(s, val >> 24)
    avio_w8(s, uint8(val >> 16))
    avio_w8(s, uint8(val >> 8))
    avio_w8(s, uint8(val))
}


But, We have to define or change the function signature of `avio_w8()` to accept `uint8`. This language doesn't compare exact with C terms. We consider pointer and equivalent for `uint8` type in Go `byte`. So, For C `*s` we can use something like its equivalent(i.e., `interface {}` or `unsafe.Pointer`) in a Go. Still these all cases depends upon function internals and used types.