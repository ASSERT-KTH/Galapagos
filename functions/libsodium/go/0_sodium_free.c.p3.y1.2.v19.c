Here is a Go equivalent version: 

go
import (
	"unsafe"
	"errors"
)

const (
	sizeofCanary         = /*equivalent of sizeof canary in c*/
	unprotectedSize	  = /*equivalent of sizeof unprotected_size in c*/
	pageSize            = /*equivalent of page_size * 2U in C, runtime calculated memory page size */
)

type (
	Canary [sizeofCanary]byte
	OutOfBoundError error
)

var (
	BasePrt *byte
	TotalSize uintptr
	ErrOutOfBounds OutOfBoundError = errors.New("_out_of_bounds")
	canary Canary = Canary{/*constant canary values equivalent of C version*/}
)

func SodiumFree(ptr unsafe.Pointer) {
	if ptr == nil {
		return
	}

	canaryPtr := (*Canary)(unsafe.Pointer(uintptr(ptr) - sizeofCanary))
	UnprotectedPtr := _unprotectedPtrFromUserPtr(ptr)
	BasePtr = UnprotectedPtr - pageSize * 2

	TotalSize = pageSize + pageSize + unprotectedSize + pageSize
	SizeOfCopyFromTotalSizeToBasePtr(BasePtr, totalSize)
	
	if DoesNotMatchCanary(*canaryPtr, canary) {
		panic(ErrOutOfBounds)
	}
	if DoesNotMatchCanary(basePtr, canary) {
		panic(ErrOutOfBounds)
	}
	(void) SodiumMUnlock(UnprotectedPtr, unprotectedSize)
	_freeAligned(BasePtr, TotalSize)
}

func DoesNotMatchCanary('^'(basePrt *UnprotectedSize, canary Canary)  { // You need to replace '^' with your appropriate variable
	l := len(canary)
	for i := 0; i < l; i++ {
		if *(*byte)(unsafe.Pointer(uintptr(unsafe.Pointer(unprotectedPtr)) + uintptr(i))) != canary[i] {
			return false
		}
	}
	return true
}

// Necessary functions need to be implemented in go because of syscall context
// You need to replace '^" with your appropriate variable
func _unprotectedPtrFromUserPtr(ptr unsafe.Pointer) *byte { '^'} // Implementation depends on your context
func ._unprotectedSizeToBasePtr(BasePtr *byte, unprotected_size uintptr)  '^'} // Implementation depends on your context
func SodiumMUnlock(IntPtr unsafe.Pointer, unprotected_size uintptr) '^'} // Implementation depends on your context
func _freeAligned(BasePtr *byte, TotalSize uintptr)'^'} // Implementation depends on your context
  

Note that given the nature of syscalls and memory operations involved, '_unprotectedPtrFromUserPtr, _DizeOfCopyFromTotalSizeToBasePtr, SodiumMUnlock,_freeAligned' functions are left unimplemented. You can fill these functions as needed.
Also, 'unprotected_size' and 'base_proof' interpretations and use may depend on your context. You may need to replace them accordingly.