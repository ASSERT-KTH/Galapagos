You should note that Go does not provide an exact equivalent to the C language pointer concept. But we 
have Garbage Collector in Golang that automatically releases memory which no longer needed.

go
func (b *ldbBuffer) clear() {
	b.data = nil
	b.size = 0
	b.alloc = 0
}


Where `ldbBuffer` is:
go
type ldbBuffer struct {
	data  []byte
	size  int
	alloc int
}
 

Please adapt the above variations as per your use-case.

Apart from that, as we don't free memory in Go, the Go garbage collector takes care of unneeded memory.
Nonetheless, if `z->data` is presenting an object from C, via `Cgo`,`C.free` should be called for `data` field to free the related memory:
Please review memory-related guidelines about cgo (C to Go pointers) in official guideline here: https://golang.org/cmd/cgo/