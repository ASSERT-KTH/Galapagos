go
import (
	"unsafe"
	"fmt"
)

func Memzero(ptr *byte, size int) {
	var buf []byte
	for i := 0; i < size; i++ {
		buf = append(buf, *ptr)
		ptr++
	}
	for i, _ := range buf {
		buf[i] = 0
	}
}

Please note: I used the `byte` type since Golang doesn't have a pre-built version of `void *`. Byte equivalence was used instead. This procedure may not bear the same semantic definition as the initial C function as it's more confusing to directly translate a void pointer in Go.  Also Go doesn't support inbuilt function for memory handling similar to C's memset or SecureZeroMemory. In Go all objects are initialized to zero.