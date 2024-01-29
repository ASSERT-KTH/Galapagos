Here is a semantically equivalent function in the Go programming language.

go
package main
import (
	"golang.org/x/sys/unix"
	"unsafe"
)

func sodium_memzero(pnt unsafe.Pointer, len uint) {
	b := (*[1 << 30]byte)(pnt)[:len:len]
	for i := range b {
		b[i] = 0
	}
	unix.Madvise(b, unix.MADV_DONTNEED)
}


This Go version of the `sodium_memzero` function accepts a pointer to an unspecified type (`unsafe.Pointer`) and a length (`len uint`). Inside the function, it casts the pointer to a byte slice. The byte slice represents a memory area starting at the pointer and being of' len' length.`len` must be less than or equal to `(1<<30)-1`. The loop sets each byte in this region to zero. Lastly, it also uses `unix.Madvise` with the flag `MADV_DONTNEED`behavior similar to some architectures of the sodium_memzero implementation, as this will tell the kernel that we don't care about the contents anymore and reduce the chance of the zeroed data persisting in memory.

This function does not match all cases of the original C function given particular flags. These cases cannot be represented in Go as Go abstracts system specific behaviors and doesn't allow compiler specific code like the C version does. The cases that haven't been represented are dynamic calls to memory zero out functions and some LTO prevention inline assembly logic. The provided code gives the optimization resistant semantic of the original function, minus memset_s equivalent (like stdlib.memset_s) would exist in Go, or LTO related `__asm__` block and SecureZeroMemory. 

Please adjust the above solution according to your exact use-case and environment.

Some details of your environment such as whether or not LTO is used and assumptions of thread and process isolation, security model details, risks associated(volatile, reads,allocation timing), etc., expose different parts of the problem and therefore will have differently optimized and ideal solutions and it might be beneficial to in such cases subsection study how 'secure' clearing might be done in memory and its challenges. Please get professional advice where required.

Representation of system specific calls are omitted, Given a Go runtime function, should one exist, that promises e.g. never being removed during, these should be substituted where most appropriate.