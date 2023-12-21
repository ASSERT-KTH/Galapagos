The Go language doesn't support preprocessor directives and also lacks the binary shift operator overloading provided by other languages like C. Moreover, Go doesn't provide the bit-specific type "uint8_t" used in the original C function, yet it provides the uint8 type which is semantically the same.

This is the list of corresponding estimations:

* GetBitContext : Go Struct.
  * C Pointer (*) : Go Pointer (& in Go.)
  * -> : . in Go.
* uint8_t : uint8 in Go.

Taking these factors into consideration, Here is a translation of your get_bits1 function from C to Go. It differs in some aspects because of benefits in Go, but semantically, they correspond.

Go
type GetBitContext struct {
	buffer                 []uint8
	index, size_in_bits_plus8    uint                         
}

func get_bits1(s *GetBitContext) uint {   
	var result uint
	index := s.index   
	
	result = uint(s.buffer[index >> 3])

	if !CHECK_BIG_ENDIAN {
		result >>= index & 7
		result &= 1
	} else {
 		result <<= index & 7
 		result >>= 8 - 1
	}

	 // Correspond to USE_UNCHECKED_BIT_STREAM_READER
	 if !(s.index < s.size_in_bits_plus8) {
		 index++
		 s.index = index
	 }

	return result                                               
}


Note: Replace `CHECK_BIG_ENDIAN` with the means you have to check for endianness in GO .

* Little endian is equivalent to `#ifdef BITSTREAM_READER_LE`
* Big endian is equivalent to `#else` of BITSTREAM_READER_LE directive.

and `USE_UNCHECKED_BIT_STREAM_READER` with your implementation-
Unchecked bitstream reader = It increments index only in case of `index < s->size_in_bits_plus8`.