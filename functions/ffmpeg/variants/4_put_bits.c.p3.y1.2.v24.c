Here is semantically equivalent code in Go, assuming the struct Jpeg2000EncoderContext and it's member fields behave in a Go's way:

go
type Jpeg2000EncoderContext struct {
    bit_index int
    buf       *[]byte
}

func put_bits(s *Jpeg2000EncoderContext, val int, n int) { // TODO: optimize
    for n > 0 {
        if s.bit_index == 8 {
            s.bit_index = 0
            if (*s.buf)[0] == 0xff {
                s.bit_index = 1
            }

            newBuf := make([]byte, len(*s.buf)+1)
            copy(newBuf, *s.buf)
            newBuf[len(newBuf)-1] = 0
            s.buf = &newBuf
        }
        (*s.buf)[len(*s.buf)-1] |= byte(val) << byte(7-s.bit_index)
        s.bit_index++
        n--
    }
}

This solution might not be exactly the same because Go doesn't handle pointer arithmetic like C does, but it attempts to keep similar function signature and behaviors. Buffers in Go are slices, which do not require dereferencing like pointers in C, hence some of the deference-related details are omitted. This solution grows the internal buffer 's.buf' by reslicing, replicating pointer increment in C.

The lack of affordable pointer arithmetic in Go restricts us from performing operations precisely like the C code, so not all the edge-cases might behave exactly the same. Therefore, a translation from C where pointer utilities are critically used could be profusely confusing or may not be possible as Go emphasises on manipulating slices or arrays instead.