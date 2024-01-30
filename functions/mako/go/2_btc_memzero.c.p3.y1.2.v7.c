import (
    "unsafe"
    "syscall"
)

func btc_memzero(ptr unsafe.Pointer, len uintptr) {
    if len > 0 {
        syscall.Syscall(syscall.SYS_MEMSET, uintptr(ptr), 0, len)
    }
}