import "C"

//export btc_free
func btc_free(ptr unsafe.Pointer) {
    if ptr == nil {
        panic("Null pointer exception") //or os.Exit(1)
    }
    C.free(ptr)
}