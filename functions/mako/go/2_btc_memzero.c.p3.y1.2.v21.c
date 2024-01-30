go
import "C"
import "unsafe"

func BtcMemzero(ptr unsafe.Pointer, len uintptr) {
    if len > 0 {
        C.memset(ptr, 0, C.size_t(len))
    }
}

This uses the cgo package in Go language to interoperate with C. Please note that Go strongly emphasizes on safety and natively doesn't allow such unsafe memory manipulation but for interoperability and  bridging with C or other programming languages, it provides unsafe and cgo packages. Attempt above works on the premises that C standard library is present to access C.memset function. It doesn't literally convert SecureZeroMemory of windows or inline assembly block of C code but assumes C.memset will behave appropriately in relevant OS/architecture.