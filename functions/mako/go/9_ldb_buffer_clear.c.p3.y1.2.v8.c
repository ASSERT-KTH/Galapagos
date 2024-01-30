go
func (z *LDBBuffer) LDBBufferClear() {
	if z.alloc > 0 {
		z.data = nil
	}

	z.alloc = 0
	z.size = 0
}


Explanation:
On Go, when you set a pointer, slice or map to `nil` the garbage collector will recognize that there is no recognizable references to the related data and will program for immediate or later clean-up (`ldb_free(z->data);`). The function signature and object receiver were also adjusted to fit struct methods on Go where "LDBBuffer" is an struct with this signature:


type LDBBuffer struct {
	data []byte
	size, alloc int
}

On Go, slices (the equivalent for an C's dynamic array / pointer with allocated length) metadata does not contain an information about the allocated size. `cap()` will return the maximum size it can grow until it needs re-allocate and this is not guaranteed to be preserved after GC executed `nil` assignment. Thus, there is no equivalent to `z->alloc`.

Please adjust against your specific data structure needs and mapping considerations.