go
import (
	"os"
)

func btcMalloc(size int) []byte {
	if size < 0 {
		os.Exit(1)
	}

	ptr := make([]byte, size)
	return ptr
}

Please note that in Go there is no exact equivalent for `malloc` or `abort` as Go manages memory allocation automatically and does not permit direct memory access unlike C. `make` is used as a way to allocate memory. Also, `os.Exit(1)` is used to mimic `abort` behavior, closing program execution, commonly because an abnormal reason.