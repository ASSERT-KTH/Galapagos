import (
    "os"
    "unsafe"
)

func btc_free(ptr unsafe.Pointer) {
    if ptr == nil {
        os.Exit(1)
    }

    C.free(ptr)
}
(Note: In Go we don't really use free as Go manages all the memory allocations and deallocation automatically. So this code would reasonably suit rare situations in which C's memory management with free is used through the unsafe package)