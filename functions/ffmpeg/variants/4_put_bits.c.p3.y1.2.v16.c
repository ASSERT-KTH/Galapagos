The Go version could look as follow:

Go
func putBits(s *jpeg2000EncoderContext, val int, n int) {
    for n > 0 {
        if s.bitIndex == 8 {
            s.bitIndex = 0
            if *s.buf == 0xff {
                s.bitIndex = 1
            }
            s.buf++
            *s.buf = 0
        }

        *s.buf |= byte(val << (7 - s.bitIndex))
        s.bitIndex++
        n--
    }
}
 

Note: It's assumed that `jpeg2000EncoderContext` is a Go object which has been predefined in your solution, something like
Go
type jpeg2000EncoderContext struct {
    buf      *uint8
    bitIndex int
}

