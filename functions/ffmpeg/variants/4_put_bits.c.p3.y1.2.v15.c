Go
type Jpeg2000EncoderContext struct {
    bit_index int
    buf       *[]byte
}

func put_bits(s *Jpeg2000EncoderContext, val int, n int) { // TODO: optimize 
    for n > 0 {
        if s.bit_index == 8 {
            if (*s.buf)[len(*s.buf) - 1] == 0xff {
                s.bit_index = 1
            } else {
                s.bit_index = 0
            }
            *s.buf = append(*s.buf, 0)
        }
        (*s.buf)[len(*s.buf) - 1] |= byte(val << (7 - s.bit_index))
        s.bit_index++
	n--
    }
}

Note: The '== 0xff' is used to give 's->bit_index' a boolean value and in Go, you can't assign boolean values to integer variable so I have replaced it with an if-else statement. I have kept the equivalent byte check condition. The pointer arithmetic present in original C code cannot be directly translated into Go which is memory-safe and doesn't allow for that sort of operations. So, Instead of explicitly moving the data length, I am updating the last byte in the buffer slice. Golang doesn't support increment(in-place) operation on slice like '++s->buf', so instead we manually add a zerobyte using the 'append' function and update 's->buf' to point to this new, extended slice. Also for increment of 's->bit_index', moved it to separate statement as there is no post increment in GO.
