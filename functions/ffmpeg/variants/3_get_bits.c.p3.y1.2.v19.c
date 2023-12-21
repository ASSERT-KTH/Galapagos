In Go, it could look something like this:

go
type Jpeg2000DecoderContext struct {
    bitIndex int
    g        bytestream2
}

func (s *Jpeg2000DecoderContext) GetBits(n int) int {
    res := 0
    for n--; n >= 0; n-- {
        res <<= 1
        if s.bitIndex == 0 {
            s.bitIndex = 7
            if s.g.GetByte() != 0xFF {
                s.bitIndex++
            }
        }
        s.bitIndex--
        res |= (s.g.PeekByte() >> uint(s.bitIndex)) & 1
    }
    return res
}


Please note, however, that bytestreams in Go would have to accommodate bytestream2 from the original code snippet, in order for it to work. The same case may apply to the GetByte() and PeekByte() methods invoked on bytestream2 structure.
   
The above code considers Jpeg2000DecoderContext as a structure (struct) instead of a pointer; moreover, in Go it's customary to use camel case instead of underscore-based phrasing for variables and functions names according to Go's naming convention. Also, the GetBits function is considered a method of the Jpeg2000DecoderContext struct.