import "os"

func btcMalloc(size int) []byte {
    var ptr []byte

    ptr = make([]byte, size)
    if ptr == nil {
        os.Exit(1)
    }

    return ptr
}