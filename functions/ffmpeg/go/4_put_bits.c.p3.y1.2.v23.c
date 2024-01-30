There isn't an explicit direct translation of the initials C function to Go, due to different languages convention. More information needed to access the clear way for conversion of each part since it handles very low-level details and uses significant features with big differences between Go and C.

However, assuming we know that `Jpeg2000EncoderContext` might be a struct with two fields `buf` and `bit_index` and asserting some knowledge on handling of bitwise operators, here is an equivalent code in Golang using its conventions.

golang
type Jpeg2000EncoderContext struct {
	buf []byte
	bit_index uint
}
func PutBits(s *Jpeg2000EncoderContext, val int, n int) { // TODO: optimize
	for n > 0 {
		n--
		if s.bit_index == 8 {
			if s.buf[0] == 0xff {
				s.bit_index = 1
			} else {
				s.bit_index = 0
			}
			s.buf = append(s.buf[1:], byte(0))
		}
		s.buf[0] |= byte(val) << uint((7 - s.bit_index))
		s.bit_index++
	}
}

  
The snippets covers basic idea of converting states like `static void` to `func` and replacing `*` with` &` and using lowerCamelCase instead of snake_case again to conform golang conventions. Remember when indexing buf pointer in the initial C construct is replaces so for every call of PutBits function we use the next index of buf every time.
 
This translation required to make assumptions like buffer s->buf is indeed a pointer and bit index is also a pointer, and assumptions about their data types, which might not be accurate without additional context, which results in assumptions in Go syntax as well primarily with slice and various kinds of operators.
        
Nonetheless, this is a best-guess effort given available information. Information about precise working and methods to improve the algorithms could lead to wildly different code in Go. Methods including concurrency and paradigm of programming hugely affect the equivalent translation here which should be decided based on provided pseudocode, more commented guide on C function or knowing what the algorithm actually represents.