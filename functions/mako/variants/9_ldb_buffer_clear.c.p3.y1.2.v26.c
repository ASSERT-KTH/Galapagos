Assuming that `ldb_buffer_t` is a struct with the fields `data`, `size` and `alloc`, the Go version function might look like this:

go
func ldbBufferClear(z *ldbBufferT) {
	if z.alloc > 0 {
		z.data = nil
		z.alloc = 0
	}

	z.data = nil
	z.size = 0
}


Please note that memory management is automatic in Go and there's no equivalent for `free`. The garbage collector will take care of releasing the memory when there are no references to the data. If `z.data` is some kind of a custom type which holds a resource that needs to be manually released, you might want to provide a manual `Release` or `Close` method for this type.
If `z.alloc` field meant to signify allocated size upfront (which is uncommon in Go), it also might be needed to slice `z.data` nil or to a predefined length.
Additional `z.alloc` resetting is made conditional modeling original behavior that it was made on successful freeing of data.