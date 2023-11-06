In Go, assuming that `GetBitContext` is defined something like this:
go
type GetBitContext struct {
	index    uint
	buffer   []byte
	sizeInBitsPlus8 uint
}

The function `get_bits1` might look like this:

go
func (s *GetBitContext) GetBits1() uint {
	index := s.index
	var result uint = uint(s.buffer[index>>3])

	if BITSTREAM_READER_LE == true {
		result >>= index & 7
		result &= 1
	} else {
		result <<= index & 7
		result >>= 8 - 1
	}

	if s.index < s.sizeInBitsPlus8 {
		index++
	}
	s.index = index

	return result
}

The above GetBits1() function is defined with Go's method syntax, because it seems the original C function was a method of a `GetBitContext` struct. However, according to Go practice, you might want to choose a different name for this method. In Go, it's rare for method names to include `GET` which indicates not-modifying the object and this method indeed modifies the object by incrementing index. Lastely,  BITSTREAM_READER_LE should be some globally defined variable.