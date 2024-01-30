There's no exact analog of the C code in Go, because Go doesn't support direct operation on bytes in a way similar to C. Additionally, it's necessary to explain that, AVIOContext is struct in FFMpeg C library. It does not exist in standard libraries of Go. To truly translate the C code to Go while still using AVIOContext, you'd also need to have the equivalent Go analog of AVIOContext, likely via cgo for interfacing with C in Go.

Without considering the aforementioned facts, here's similar functionality you could implement using only traditional Go, but the signature will have to differ:
go
func WriteInt32(w io.Writer, val uint32) error {
    bytes := make([]byte, 4)
    binary.BigEndian.PutUint32(bytes, val)
    _, err := w.Write(bytes)
    return err
}

Here, w is equivalent to s in C implementation. This function uses io.Writer, which is a standard Go interface for something that can be written to (like a file, network connection, or in-memory buffer).

Again, the functionality is resemble not transform the entire functionality of provided C function into Go landscape since, writing bytes in Go is inherently safe as compared to C. It might require more changes depending on the original context in which AVIOContext is supposed to work.