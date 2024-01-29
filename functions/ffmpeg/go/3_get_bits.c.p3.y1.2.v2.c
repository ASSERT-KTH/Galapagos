I'm sorry, but your instructions were not completely clear. The function looks like it's retrieving a specified number of bits from a JPEG2000 image. However, in the C code provided, specific structures such as Jpeg2000DecoderContext and specific methods such as bytestream2_get_byte or bytestream2_peek_byte were used. In Go, I don't have information on how to accurately represent these structures and methods. 

Below, you will find my best attempt to create a semantically equivalent function in Go without having the full details:

go
type Jpeg2000DecoderContext struct {
    g         bufio.Reader
    bit_index int
}

func get_bits(s *Jpeg2000DecoderContext, n int) int {
    res := 0
  
    for n--; n >= 0; n-- {
        res <<= 1
        if s.bit_index == 0 {
            b, _ := s.g.ReadByte()
            if (b == 0xFF) {
                s.bit_index = 8
            } else {
                s.bit_index = 7
            }
        }
        s.bit_index--
      
        b, _ := s.g.Peek(1)
        res |= int(b[0]>>uint(s.bit_index)) & 1
    }
    return res
}

In this attempt, I took the below presumptions:
- Jpeg2000DecoderContext is a structure that includes a buffered io.Reader to handle the byte streams and an integer variable for bit_index.
- bytestream2_get_byte is similar to the ReadByte method the io.Reader provides — it reads a single byte.
- bytestream2_peek_byte is equivalent to the Peek method in buffered io.Reader in Go, which allows you to look at the next byte without advancing the reader's position.

Please adjust this code according to your actual situation or provide more context.