func putBits(s *Jpeg2000EncoderContext, val int, n int) {
    for n > 0 {
        if s.bitIndex == 8 {
            s.bitIndex = 0
            if *s.buf == 0xff {
                s.bitIndex = 1
            }
            s.buf = append(s.buf, 0)
        }
        s.buf[len(s.buf)-1] |= byte(val << (7 - s.bitIndex))
        s.bitIndex++
        n--
    }
}