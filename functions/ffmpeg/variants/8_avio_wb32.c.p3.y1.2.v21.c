func avio_wb32(s *AVIOContext, val uint32) {
    avio_w8(s, uint8(val>>24))
    avio_w8(s, uint8(val>>16))
    avio_w8(s, uint8(val>>8))
    avio_w8(s, uint8(val))
}