func btcFree(ptr *unsafe.Pointer) {
  if ptr == nil {
    panic("nil pointer passed to btcFree")
  }
  
  C.free(unsafe.Pointer(ptr))
}