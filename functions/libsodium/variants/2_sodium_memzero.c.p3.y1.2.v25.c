go
import "C"
import "unsafe"

func sodiumMemzero(pnt unsafe.Pointer, len uint) {
	ptr := (*[1 << 30]byte)(pnt)
	for i := uint(0); i < len; i++ {
		ptr[i] = 0
	}
}

In the reference C code, different methods are used to clear memory based on platform support capabilities. 

There're no equivalent functions like SecureZeroMemory, memset_s, explicit_bzero, memset_explicit and explicit_memset available in go. Ordinary byte slice is used to get content of raw pointer and then set each byte manually rely on go's garbage collection.

The slice does not own the memory - it merely references it. Eventually Go runtime garbage collection or program termination will do the cleaning. And `len` is just number of byte counts from raw pointer to clear, not length of data.

Please be aware that CGo importing "C" gives possibility of memory leaking as due to current design of GC in Go, GC simply considers C.malloc allocated memory as root objects, making actual ownership and responsibility rules unclear.

And moreover, each CGo call comes with overhead depended on concrete environment. Try to minimize them. Because of that writing multi-platform based program would become not so performance friendly using CGo and even ineffective.