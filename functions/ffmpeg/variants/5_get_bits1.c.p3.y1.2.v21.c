In Go, bit manipulation and inline keywords are unnecessary because Go's execution logic optimizes it for you. And the Go language does not support the use of preprocessor directives, these can be replaced using Go's conditional statements like `if-else` 

Assuming that struct `GetBitContext` is already defined as follows:

go
type GetBitContext struct {
    Index              uint
    Buffer             []byte
    SizeInBitsPlus8    uint
}

const BITSTREAM_READER_LE = true  // Either true or false
const UNCHECKED_BITSTREAM_READER = false  // Either true or false


Then equivalent Golang function would be as follows:

go
func ( s *GetBitContext )getBits1() uint {

  index := s.Index
  var result = s.Buffer[index >> 3]
  if BITSTREAM_READER_LE {
    result >>= index & 7
    result  &= 1
  } else {
    result <<= index & 7
    result >>= 8 - 1
  }

  if !UNCHECKED_BITSTREAM_READER {
    if s.Index < s.SizeInBitsPlus8 {
      index++
    }
    s.Index = index;
  
  } return result;

}
