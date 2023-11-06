Assuming GarbageValue is a predefined constant, and _SodiumMalloc() is a predefined function that replicates the functionality of your _sodium_malloc(), this would be your Go implementation.

go
import "C"
import "unsafe"

const GarbageValue = <Your Value Here>

func SodiumMalloc(size uintptr) unsafe.Pointer {
	// Assuming _SodiumMalloc is a predefined C function you've created
	ptr := C._SodiumMalloc(C.size_t(size))
	if ptr == nil {
		return nil
	}
	GOptr := (*[1 << 30]byte)(unsafe.Pointer(ptr))

	for i := uintptr(0); i < size; i++ {
		GOptr[i] = byte(GarbageValue)
	}

	return unsafe.Pointer(GOptr)
}


Just replace <Your Value Here> in GarbageValue constant declaration with the value you set for GARBAGE_VALUE originally in C.
And ensure C._SodiumMalloc is an existing memory allocating function equivalent to your _sodium_malloc().