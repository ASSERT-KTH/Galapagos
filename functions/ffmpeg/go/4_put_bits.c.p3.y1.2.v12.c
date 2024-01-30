func putBits(s *Jpeg2000EncoderContext, val int, n int) {
    for n > 0 {
        if s.bitIndex == 8 {
            s.bitIndex = 0
            if s.buf[s.bufIndex] == 0xff {
                s.bitIndex = 1
            }
            s.bufIndex++
            s.buf[s.bufIndex] = 0
        }
        s.buf[s.bufIndex] |= byte(val << (7 - s.bitIndex))
        s.bitIndex++
        n--
    }
}