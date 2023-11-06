go
import "os"

func LdbMalloc(size uintptr) *byte {
    ptr, err := syscall.Mmap(-1, 0, int(size), syscall.PROT_NONE, syscall.MAP_ANON|syscall.MAP_PRIVATE)
    if err != nil {
        os.Exit(1);
    }
    return &ptr[0]
}
