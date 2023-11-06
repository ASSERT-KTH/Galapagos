go
func btcUint32Read(zp *uint32, xp *[]byte, xn *int) int {
  if *xn < 4 {
    return 0
  }

  if isBigEndian() {
    *zp = (uint32((*xp)[0]) << 0) |
          (uint32((*xp)[1]) << 8) |
          (uint32((*xp)[2]) << 16) |
          (uint32((*xp)[3]) << 24);
  } else {
    *zp = binary.LittleEndian.Uint32(*xp)
  }

  *xp = (*xp)[4:]
  *xn -= 4

  return 1
}

func isBigEndian() bool {
    var i int32 = 0x1
    b := (*[4]byte)(unsafe.Pointer(&i))
    return b[0] != 0
}

 Please note that, I added `isBigEndian` method to check endianness as Go does not support traditional preprocessors like `#if defined`.
Also, semantically `buf = buf[n:]` doesn't change the underlying array, whereas offsetting the pointer as in C `*xp += 4;` would move the underlying memory address.
These are semantic differences due to the nature of each language; the Go code does the equivalent operation suitable for Go's specific memory management whilst giving the same output as the C function.