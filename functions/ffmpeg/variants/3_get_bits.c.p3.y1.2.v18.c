In Go, the `Jpeg2000DecoderContext` struct might look something like this:

go
type Jpeg2000DecoderContext struct {
    g         *ByteStream
    bit_index int
}

type ByteStream struct {
    Buffer []byte
    Index  int
}

func (b *ByteStream) next() byte {
    r := b.Buffer[b.Index]
    b.Index++
    return r
}

func (b *ByteStream) peek() byte {
    return b.Buffer[b.Index]
}


Then, the `get_bits` function would be converted to a method attached to `Jpeg2000DecoderContext`, with following Go equivalent:

go
func (s *Jpeg2000DecoderContext) getBits(n int) int {
    res := 0
    for n--; n >= 0; n-- {
        res <<= 1
        if s.bit_index == 0 {
            s.bit_index = 7
            if s.g.next() != 0xFF {
                s.bit_index++
            }
        }
        s.bit_index--
        res |= (int(s.g.peek()) >> uint(s.bit_index)) & 1
    }
    return res
}


Please beware of type issues specific to working with bytes in golang, this translation piecewise of the original C code may require some adjustments depending on the specific abstractions of `ByteStream` in your codebase, and do however mind about golang's `byte` signedness and needing to use `uint` for bit-shifting as performed in `>> uint(s.bit_index)`.