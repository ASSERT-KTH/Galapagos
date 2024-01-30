func btc_memzero(ptr *byte, len uint) {
    if len > 0 {
        for i := uintptr(0); i < uintptr(len); i++ {
            *(*byte)(unsafe.Pointer(uintptr(unsafe.Pointer(ptr)) + i)) = 0
        }
    }
}