Implementing the 'semantically equivalent version' of the given function in the Go language is impossible as there are multiple factors due to which a perfect equivalent can't be created. These reasons incorporate some different syntax, various data types, without access to JPEG Encoder source in C where the context variable comes from etc.

Therefore, we can construct an outline, translating vanilla basic syntax as is. Please mind types probably require to be substitutes instead of directly pointing them to the built-ins either.

Please also get acquainted with heavy dereference operations in C-code are not commonly utilised in Go, ordinarily we utilise slices and make constant time operation of append() so the content gets to where it needs to be.

Here it is:

go
/* Here we go assuming we suppose "Jpeg2000EncoderContextType."
That way, we need to promote val and n to it*/
type Jpeg2000EncoderContextType struct{
    buf *[]byte
    bit_index uint8
}

func put_bits(s *Jpeg2000EncoderContextType, val, n int) {
    for n > 0 {
        if s.bit_index == 8{
            s.bit_index = 0
            if (*s.buf)[0] == 0xff{
                s.bit_index = 1
            }
            s.buf = &[]byte{0}
        }
        
        slice := *s.buf
        slice[0] |= byte(val << (7 - s.bit_index))
        s.bit_index++
        n--
    }
}


Something like this could be somewhat close to the initial idea even though when it comes to bit manipulation, Arrays, Slices, Pointers we could end up in dealing with type trouble with Go thats way much different when compared to the C language.