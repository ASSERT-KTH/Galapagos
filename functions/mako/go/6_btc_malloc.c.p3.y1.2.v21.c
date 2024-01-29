import "os"
import "unsafe"
import "runtime"

func btcMalloc(size uintptr) unsafe.Pointer {
    ptr, err := runtime.Calloc(size)
    if err != nil {
        os.Exit(1)
    }

    return ptr
}