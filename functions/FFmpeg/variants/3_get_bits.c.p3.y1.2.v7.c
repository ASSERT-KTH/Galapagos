Unfortunately, direct translation aimed to replicate the bit by bit operation from C to Go doesn't make sense due to the absence of useful features such as pointer manipulations or binary object-streams like bytestream in the Go language. Here, though, I've tried to formulate a version that should accomplish the identical task albeit in a different way in Go.

Go
type Jpeg2000DecoderContext struct {
    g          []byte
    bitIndex   int
    currentPos int
}

func get_bits(s *Jpeg2000DecoderContext, n int) int {
    var res int
    for n--; n >= 0; n-- {
        res <<= 1
        if s.bitIndex == 0 {
            s(bitIndex = 7
            next_byte := s.g[s.currentPos]
            s.currentPos += 1
            if next_byte != 0xFFu {
                s.bitIndex++
            }
        }

        s.bitIndex--
        res |=  int(s.g[s.currentPos] >> uint(s.bitIndex)) & 1
    }
    return res
}


This translation assumes that the 'g' in Go version is a slice of bytes(bits) not a bytestream(as int C version) and the getNextByte() function is omitted as it is implemented differently in the Go version. Also '>' operator tunes the bits so there's a need for a conversion into uint(s.bitIndex) under shifting operation.