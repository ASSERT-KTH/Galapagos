func avio_wb32(s *AVIOContext, val uint32) {
    avio_w8(s,           byte(val >> 24))
    avio_w8(s, (uint8)(byte(val >> 16)))
    avio_w8(s, (uint8)(byte(val >>  8)))
    avio_w8(s, (uint8)(byte(val)))
}