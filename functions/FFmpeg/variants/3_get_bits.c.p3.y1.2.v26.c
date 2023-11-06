Here is a semantically equivalent version in Go:

go
type Jpeg2000DecoderContext struct {
    bit_index int
    g         byte
}

func get_bits(s *Jpeg2000DecoderContext, n int) int {
    res := 0

    for ; n > 0; n-- {
        res <<= 1
        if s.bit_index == 0 {
            r := bytestream2_get_byte(&s.g)
            s.bit_index = 7 + ternary(r != 0xFF, 1, 0) 
        }
        s.bit_index--
        res |= (bytestream2_peek_byte(&s.g) >> s.bit_index) & 1
    }
    return res
}

// Addition operator that serves similar purpose as "?:" operator in C.
func ternary(cond bool, trueVal, falseVal int) int {
    if cond {
        return trueVal
    }
    return falseVal
}

func bytestream2_get_byte(g *byte) int {
    // Some implementation here
}

func bytestream2_peek_byte(g *byte) int {
    // Some implementation here
}


Adjust the bytestream2_get_byte() and bytestream2_peek_byte() following your needs.

It's important to note that Go doesn't support the ternary operator (a ? b : c), that's why I implemented a ternary function.