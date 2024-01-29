As Go does not support pointer or List/Array manipulation of elements like C/C++, semantically equivalent conversion often requires slight reframing of the methods used originally. Here is the reframed code in Go:

go
type Jpeg2000EncoderContext struct { 
    bit_index uint8
    buf []uint8
}

func put_bits(s *Jpeg2000EncoderContext, val int, n int) { // TODO: optimize
    for n > 0 {
        if s.bit_index == 8 {
            if s.buf[0] == 0xff {
                s.bit_index = 1
            } else {
                s.bit_index = 0
            }
            s.buf = append(s.buf, 0)  
        }
        s.buf[len(s.buf)-1] |= uint8(val << (7 - s.bit_index))
        s.bit_index++
        n--
    }
}

Some key changes:

1. A new struct `Jpeg2000EncoderContext` has been created, that includes `bit_index` and `buf`.

2. Since Go does not support pre or post increment property on pointer variable, updating the buffer and bit index variables is done on separate lines in a safe manner.

3. Go does not support pointer math like C, so iterating over array elements using increment operator is not possible. We use Go's built-in `append` function instead to append or manipulate the buffer/string. 

Please recheck and see if this properly preserves the semantics of your original function. As differences in language features can sometimes mean that a feature or technique used in one language (in this case, C) doesn't have an exact equivalence in another (Go). Also, if the original program relies on behaviour specific to the C language (perhaps via system calls, specific numeric overflows or casting behaviour), this may not accurately reproduce that behaviour. For maintaining the precise semantics additional adjustment would be required based on actual use case. This code forms an approximate semantic equivalent, without concerning about memory allocation optimizations, dereferencing pointers that may be required in original C code.