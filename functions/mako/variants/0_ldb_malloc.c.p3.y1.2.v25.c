go
import (
	"os"
)

func ldbMalloc(size int) []byte {
	ptr := make([]byte, size)
	if ptr == nil {
		os.Exit(1)
	}
	return ptr
}
