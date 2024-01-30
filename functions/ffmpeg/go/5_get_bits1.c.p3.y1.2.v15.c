The Go equivalent of the aforementioned code would be:

go
func get_bits1(s *GetBitContext) uint8 {
    index := s.index
    result := s.buffer[index >> 3]
    if !BITSTREAM_READER_LE {
        result <<= index & 7
        result >>= 8 - 1
    } else {
        result >>= index & 7
        result &= 1
    }
    if !UNCHECKED_BITSTREAM_READER {
        if s.index < s.size_in_bits_plus8 {
            index++
        }
    }
    s.index = index

    return result
}


Note: Language's builtin constants, bitwise and other operators have been used as direct replacement of C macros and operators. Replace them with actual constant values or functions.

- In go programming language, language keywords are case insensitive.
- Postfix increment/decrement (like `i++`/`i--`) is the only form valid in go lang. You cannot use prefix increment like `++i`
- In place of C macros, global constants have differentiated in uppercase like BITSTREAM_READER_LE and UNCHECKED_BITSTREAM_READER. Calculate as per needed.
- Defining and reassigning of `index` was adapted to Golang’s syntax.