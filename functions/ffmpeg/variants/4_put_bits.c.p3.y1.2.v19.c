In Go, we'll have to create a sample `Jpeg2000EncoderContext` to replicate the behavior of `put_bits()`. 

Here is your equivalent Go program:

go
type Jpeg2000EncoderContext struct {
	Buffer    []byte
	BufferIdx int
	BitIdx    int
}


func (s *Jpeg2000EncoderContext) put_bits(val int, n int) { // TODO: optimize
	for n > 0 {
		if s.BitIdx == 8 {
			s.BitIdx = 0
			if s.Buffer[s.BufferIdx] == 0xff {
				s.BitIdx = 1
			}
			s.BufferIdx++
			s.Buffer[s.BufferIdx] = 0
		}
		s.Buffer[s.BufferIdx] |= byte(val) << byte(7-s.BitIdx)
		s.BitIdx++
		n--
	}
}


Note:

1. Go does not allow process/package level function declarations (C-style Functions) to alter struct-level attributes. We need to declare the function as a receivable method of a given struct to make changes using a pointer to that Struct (which `Jpeg2000EncoderContext` object `s` is).
2. The `*` operator in `*s` in C denotes that `s` is a pointer; we are not dereferencing the pointer here like we would in C. Rather, we are merely using the object that the pointer is referring to, the struct `Jpeg2000EncoderContext`.
3. In Go language, to decrease the number explicitly, `n--` is used as `n-- > 0` will not work as it does in C.
4. The typecasting of integers to byte over in Go, since the `Buffer` take bytes only.
