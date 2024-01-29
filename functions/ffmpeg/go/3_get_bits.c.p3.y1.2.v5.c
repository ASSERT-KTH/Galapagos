This version of your function written in go is equivalent in the range of return types and operation for the assumedly equivalent types. You would have to run tests to check its validity against the original function implementation due to some conditions ingrained in C programmers syntax that may be not explicitly state conditions in the C code. Nonetheless, here is the possible conversion of such function in Go:

go
type Jpeg2000DecoderContext struct {
    bit_index int
    g          *ByteStream2
}

type ByteStream2 struct {
    // many attributes
}

func (bs *ByteStream2) getByte() int {
    // read a byte
    return 0
}

func (bs *ByteStream2) peekByte() int {
    // peek a byte
    return 0
}

func getBits(s *Jpeg2000DecoderContext, n int) int {
    res := 0
    for n--; n >= 0; n-- {
        res <<= 1
        if s.bit_index == 0 {
            s.bit_index = 7 + oneIf(s.g.getByte() != 0xFF)
        }
        s.bit_index--
        res |= (s.g.peekByte() >> s.bit_index) & 1
    }
    return res
}         

// The original C code checks if (s->g.getByte() != 0xFFu), and if that's true it increments the bit_index by '1', if it's false, it doesn't. The very same role is done by the following function.
func oneIf(condition bool) int {
    if condition {
        return 1
    }
    return 0
}


Please notice that there seems to be an intrinsic data type in image manipulation part on C originated library that there is not a readily-for-use match in pre-defined types in go. Namely, each tailored library many widely use languages conveniently created the necessary types in order to support intricate procedures in it.
I've assumed the existence of analogous bytestream procedures in go as it's being commonly implemented as a native language chunk of data manipulation methods, yet if it is needing custom implementations of how to get or peek a byte, such approach could affect possibly hidden conditions and outcomes to the biggest detail of how `Jpeg2000DecoderContext` involves its properties.
