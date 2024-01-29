go
import (
    "os"
    "unsafe"
)

func btcMalloc(size uintptr) unsafe.Pointer {
    ptr, err := os.NewProc(1, size).Alloc()

    if err != nil {
        os.abort()
    }
    return ptr
}

The Go program is similarly aborting system in case of memory allocation failure because os.NewProc(1, size).Alloc() provides similar functionality as the original in providing dynamic array functionality with safety checks. If it cannot secure memory it raises a panic which will lead to program termination much like the original. Please note that this method could behave differently on various platforms due reasons like varying implementaions of the Go's os and unix libraries across different platforms among other variables, therefore making it difficult to perfectly map over semantics from C. 

Also, unsafe.Pointer is a pointer type that's special in Go. It's a way to manipulate memory directly and is equivalent to a C 'void *' pointer. To use it you have to import the "unsafe" package. 

I have used uintptr for size followig standard Go semantics.

Further Improvements: It's typically considered unacceptable to terminate the application if memory allocation fails because Go manages memory. If such a fail was to occur it likely indicates extreme circumstances at the systems level. Alternatively you can return the error and handle it at a higher level as appropriate in your application insteadb of calling os.abort(). This would provide better usability, scalability and response to problems in actual use and goes with Go idiomatic error handling practices.