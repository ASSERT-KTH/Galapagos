Here's the Go equivalent:

go
import (
	"C"
	"unsafe"
)

func btc_free(ptr unsafe.Pointer) {
	if ptr == nil {
		panic("nil pointer passed to btc_free")
	}
	C.free(ptr)
	return
}


However, note that effective Go use prefers not to use `unsafe.Pointer`; in the big picture, explicit memory management means dealing with errors from `free`, and similar which Go handles very well automatically if you omit the unsafe import. Furthermore, freeing memory is not a safe operation and should be explicitly done by the Go garbage collector, not manually by the programmer. That's why Go doesn't expose a `free` function like the C standard library.