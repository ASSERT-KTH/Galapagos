import "os"

func btc_malloc(size uintptr) *byte {
    ptr, err := C.malloc(size)

    if err != nil {
        os.Exit(1)
    }

    return (*byte)(ptr)
}