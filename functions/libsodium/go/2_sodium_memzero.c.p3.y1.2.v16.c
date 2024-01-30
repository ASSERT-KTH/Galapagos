Go does not directly support conditional compilation or inline assembly like C, and it uses a garbage collected memory model, therefore direct manual memory management is more limited. Still we could achieve the main goal (writing zeros to an array or slice) in a very straightforward way. 

Here is equivalent implementation:

golang
import "C"

func sodium_memzero(pnt unsafe.Pointer, len C.size_t) {
	ptr := (*[1 << 30]C.char)(pnt)
	for i := 0; i < int(len); i++ {
		ptr[i] = 0
	}
}
