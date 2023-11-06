func btcFree(ptr *unsafe.Pointer) {
    if (ptr == nil) {
        os.Exit(1)
    }

    C.free(unsafe.Pointer(ptr))
}