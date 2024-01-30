Assuming `ldb_buffer_t` is represented as a struct in Go, as

go
type ldb_buffer_t struct {
    Data  []byte
    Size  int
    Alloc int
}


The semantically equivalent function of `ldb_buffer_clear` in Go is:

go
func ldb_buffer_clear(z *ldb_buffer_t) {
    if z.Alloc > 0 {
        z.Data = nil
    }
    z.Size = 0
    z.Alloc = 0
}

In Go, memory management is done automatically so there's no exact equivalent for the `ldb_free()` function in the original C function. Setting `z.Data` to `nil` should allow Go's garbage collector to free the memory previously assigned to `z.Data`, provided no other portions of your program retain a reference to the same underlying memory.