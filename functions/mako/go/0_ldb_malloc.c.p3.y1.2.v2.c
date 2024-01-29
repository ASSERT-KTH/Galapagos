Go
import (
    "os"
)

func ldbMalloc(size int64) []byte {
    ptr := make([]byte, size)

    if ptr == nil {
        os.Exit(1)
    }

    return ptr
}
