func btcFree(ptr unsafe.Pointer) {
    if ptr == nil {
        log.Panic("Nil pointer passed to free() function")
    }
    C.free(ptr)
}