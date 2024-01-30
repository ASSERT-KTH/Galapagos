Unfortunately, directly translating an equivalent version of this function to Go is technically impossible due to the differences in how the two languages handle pointers and manage memory. C gives the developer a lot of control over memory, enabling pointer arithmetic, direct memory allocation or deallocation, etc.; Go, on the other hand, provides Garbage Collector and does not support pointer arithmetic for the sake of safety. However,understanding the logic of the function, here is a representation in Go that does similar bit operations:

Note: Please adjust the logic according to your exact application.

Go
type Jpeg2000EncoderContext struct {
    buf       *[]byte
    bit_index int
}

func (s *Jpeg2000EncoderContext) put_bits(val int, n int) {
    for n > 0 {
        if s.bit_index == 8 {
            s.bit_index = 0
            if (*s.buf)[len(*s.buf)-1] == 0xff {
                s.bit_index = 1
            } 
            *s.buf = append(*s.buf, 0)
        }
        (*s.buf)[len(*s.buf)-1] |= byte(val) << uint(7-s.bit_index)
        s.bit_index++
        n--
    } 
}


This variant attempts to replicate the C function; ensuring that it will keep adding to a byte array while constantly checking the last element of the slice (buff). As originally as for bitwise shifting , it's originally translate from C to Go (just swapping operand positions as necessary), keep in mind that in Go you need to explicit type conversions.