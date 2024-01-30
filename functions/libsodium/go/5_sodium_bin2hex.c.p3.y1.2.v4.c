go
func sodiumBin2Hex(hex *[]byte, hexMaxLen int, bin *[]byte, binLen int) *[]byte {
    const SIZE_MAX = ^uint(0)
    var i uint
    var x uint32
    var b, c byte

    if uint(binLen) >= SIZE_MAX / 2 || uint(hexMaxLen) <= uint(binLen) * 2 {
        panic("sodium misuse")
    }
    for i = 0; i < uint(binLen); i++ {
        c = (*bin)[i] & 0xf
        b = (*bin)[i] >> 4
        x = uint32(87 + uint(c) + uint((c - 10) >> 8 & ^38)) << 8 |
            uint32(87 + uint(b) + uint((b - 10) >> 8 & ^38))
        (*hex)[i * 2] = byte(x)
        x >>= 8
        (*hex)[i * 2 + 1] = byte(x)
    }
    (*hex)[i * 2] = 0

    return hex
}
