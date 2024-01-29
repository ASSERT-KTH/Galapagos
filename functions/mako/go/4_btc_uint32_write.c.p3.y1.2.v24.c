go
func btc_uint32_write(zp *[]byte, x uint32) *[]byte {
    if isBigEndian() {
        *zp = append(*zp, byte(x >> 0))
        *zp = append(*zp, byte(x >> 8))
        *zp = append(*zp, byte(x >> 16))
        *zp = append(*zp, byte(x >> 24))
    } else {
        *zp = append(*zp, uintToBytes(x)...)
    }
    return zp
}

func uintToBytes(n uint32) []byte {
    x := uint32(n)

    bytesBuffer := bytes.NewBuffer([]byte{})
    binary.Write(bytesBuffer, binary.LittleEndian, x)

    return bytesBuffer.Bytes()
}

func isBigEndian() bool {
   var i int = 0x1
   bs := (*[4]byte)(unsafe.Pointer(&i))
   return bs[0] == 0
}
