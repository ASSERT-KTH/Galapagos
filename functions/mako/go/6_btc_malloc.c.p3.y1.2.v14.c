go
import (
    "log"
    "os"
)

func btc_malloc(size uint) *byte {
    ptr := make([]byte, size)
    
    if ptr == nil {
        log.Fatal("Out of memory")
        os.Exit(1)
    }

    return &ptr[0]
}

Notice that Go handles low-level errors like out of memory itself. The os.Exit(1) is not necessary just like abort in C. The Go runtime would panic when it cannot allocate memory which is similar. We can force an out-of-memory situation using if ptr == nil for educational purposes. However, ptr will never be nil in Go; make will panic before that happens. So while os.Exit(1) has been added to provide the same functionality as in the given function, in reality, this check if ptr == nil is not needed. Also Go does not allow giving low-level pointers to high level language thus, this function is returning a pointer to a byte array instead. Therefore, it doesn't 100% mimic the C code provided but provides a similar functionality.