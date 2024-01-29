func btcMemzero(ptr unsafe.Pointer, len uintptr) {
  if len > 0 {
    mem := (*[1 << 30]byte)(ptr)
    for i := uintptr(0); i < len; i++ {
      mem[i] = 0
    }
  }
}