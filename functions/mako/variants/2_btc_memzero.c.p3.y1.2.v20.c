Go
import "unsafe"
import "runtime"

// Dummy function since Go doesn't have asm inline assembly
// or direct access to any sort of SecureZeroMemory 
func ZeroMemory(ptr unsafe.Pointer, size uintptr)

func btc_memzero(ptr unsafe.Pointer, len uintptr) {
    if len > 0 {
        runtime.KeepAlive(ptr)
        ZeroMemory(ptr, uintptr)
    }
}
