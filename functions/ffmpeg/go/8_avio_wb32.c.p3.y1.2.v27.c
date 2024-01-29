func avioWb32(s *AVIOContext, val uint32) {
    avioW8(s, uint8_t(val >> 24))
    avioW8(s, uint8_t((val >> 16) & 0xFF))
    avioW8(s, uint8_t((val >> 8)  & 0xFF))
    avioW8(s, uint8_t(val & 0xFF))
}