func btc_uint32_write(zp []byte, x uint32) []byte {
  if isBigEndian() {
    zp[0] = byte(x)
    zp[1] = byte(x >> 8)
    zp[2] = byte(x >> 16)
    zp[3] = byte(x >> 24)
  } else {
    binary.LittleEndian.PutUint32(zp, x)
  }
  return zp
} 

func isBigEndian() bool {
    var x uint16 = 0x0102
    return []byte{0x01, 0x02} !=
           (*[2]byte)(unsafe.Pointer(&x))[:]
}