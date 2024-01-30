As Go does not support function pointers in struct, we need to use an `interface` to reach a kinda correspondence of the C code to Go. Similarly to `funcpointer *randombytes_implementation` statement in the original C code, we would implement an interface named `RandombytesImplementation`, and define `InitIfNeeded()` and `Buf([]byte, uint)` methods that might be needed by the `RandombytesImplementation` interface.

go
type RandombytesImplementation interface {
	InitIfNeeded()
	Buf([]byte, uint)
}

var Implementation RandombytesImplementation

func RandombytesBuf(buf []byte, size uint) {
	Implementation.InitIfNeeded()
	if size > uint(0) {
		Implementation.Buf(buf, size)
	}
}


Before using `RandombytesBuf`, you need to implement `RandombytesImplementation` and assign the implementated object to variable `Implementation`.

The Go equivalent uses byte slices (`[]byte`) instead of void pointers (`void*`), and `uint` instead of `size_t` since Go does not explicitly support unsigned integer with width same as the pointer.

They may not be exactly equivalent because of some difference and features between two languages. 
For instance, Go doesn't have void pointers or a size_t type, and go encourages not to use the underscore in the variable's name.
Also, in go, libraries or packages are supposed to be a black box without possibility of monkey patching but should be able to be substituted with other compatible implementations. Hence users would never directly call something like `implementation->buf()`. On the contrary, libraries provide functions as the APIs. Libraries (packages) utilise the internal functions to implement APIs themselves instead of providing all the provided functionalities by their contents to the users directly.