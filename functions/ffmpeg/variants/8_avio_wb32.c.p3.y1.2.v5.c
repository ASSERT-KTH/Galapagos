func avioWb32(s *AVIOContext, val uint32) {
    avioW8(s, uint8(val >> 24))
    avioW8(s, uint8(val >> 16))
    avioW8(s, uint8(val >> 8))
    avioW8(s, uint8(val))
}