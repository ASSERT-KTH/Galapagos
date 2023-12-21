The C language code uses undefined types and operations linked to specific data types, which complicates the transposition to Go directly maintaining the original function signature. So this version will have to use a defined structure and methods in Go for correct functioning:

go
type Jpeg2000DecoderContext struct {
    bitIndex uint
    g        *ByteStream
}

func (s *Jpeg2000DecoderContext) getBits(n int) int {
    res := 0

    for n--; n >= 0; n-- {
        res = res << 1
        if s.bitIndex == 0 {
            if s.g.getByte() != 0xFF {
                s.bitIndex = 7
            } else {
                s.bitIndex = 8
            }
        }
        s.bitIndex--
        res = res | int((s.g.peekByte() >> s.bitIndex) & 1)
    }
    return res
}

Note: `ByteStream` used in `Jpeg2000DecoderContext` struct and methods like getByte() and peekByte() are only placeholders and should be replaced as necessary to directly map from your original byte stream handling constructs used in your code base. Without knowing the structure and functionality of the `bytestream2_get_byte` and `bytestream2_peek_byte`, I cannot provide a more detailed translation.