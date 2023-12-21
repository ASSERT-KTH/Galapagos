Go
func putBits(s *Jpeg2000EncoderContext, val int, n int) {
    for n > 0 {
        if s.bitIndex == 8 {
            s.bitIndex = b2i(*s.buf == 0xff)
            s.buf = append(s.buf, 0)
        }
        s.buf[s.bufindex] |= byte(val << (7 - s.bitIndex))
        s.bitIndex++
        n--
    }
}

// b2i returns 1 if b is true and 0 if false.
func b2i(b bool) int {
    if b {
        return 1
    }
    return 0
}
