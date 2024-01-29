Here is a translation to Go. In Go, the bitwise shift and OR operations are similar to C. The main differences in this conversion involve type handling and accessing properties of the struct.

In Go, bit manipulations should be carried with due care as it implicitly uses unsigned shifts, unlike C. Also, the equivalence of get_byte and peek_byte methods called through s->g would have to be devised according to the Go Implementation of Jpeg2000DecoderContext, which here, to define generic code, we define by using methods NextByte and CurrentByte.

We often forget that Go is not Object-Oriented Programming, all objects should be pass as pointers if we might change variables.

 Go
type Jpeg2000DecoderContext struct {
    bitIndex int
    g        *ByteStream // Assuming you defined ByteStream elsewhere
}

// getBit retrieves 'n' bits.
func (s *Jpeg2000DecoderContext) getBits(n int) int {
    res := 0

    for n--; n >= 0; n-- {
        res <<= 1
        if s.bitIndex == 0 {
            nextByteNotFF := (s.g.NextByte() != 0xFF)
            s.bitIndex = 7
            if nextByteNotFF {
                s.bitIndex++
            }
        }
        s.bitIndex--
        res |= int((s.g.CurrentByte() >> uint(s.bitIndex)) & 1)
    }
    return res
}

// ByteStream - A stub until you create your ByteStream definition
type ByteStream struct{}

// Assuming similar operation to bytestream2_get_byte
func (*ByteStream) NextByte() byte {
    return 0 
}

// Assuming similar operation to bytestream2_peek_byte
func (*ByteStream) CurrentByte() byte {
    return 0 
}


Would alter once you define how ByteStream is set up. All '0' return methods that represent your equivalent methods with Jpeg2000Decoder which I could not define without your code towards returning last byte and current byte as required or if different.

Correct error handling and testing, this simplified version focuses merely on showing how one may move from C to Go, particularly for such API issues.