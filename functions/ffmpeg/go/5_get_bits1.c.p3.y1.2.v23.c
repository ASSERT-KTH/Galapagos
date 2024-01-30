Here is the Go version:

go
type GetBitContext struct {
    index int
    sizeInBitsPlus8 int
    buffer []byte
}

func getBits1(s *GetBitContext) uint8 {
    index := s.index
    result := s.buffer[index >> 3]
    result >>= index & 7
    result &= 1
    if s.index < s.sizeInBitsPlus8 {
        index++
    }
    s.index = index

    return result
}


Notes:

- I've translated the C `unsigned int` to a `uint` in Go.
- Your `#ifdef` blocks seem to control different versions of this logic in response to different compile-time flags like `BITSTREAM_READER_LE`. To reproduce this exactly in Go would not be practical as it doesn't have pre-processing or compile-time flags in quite the same way. 
- However, the business logic underneath both `#ifdef` and `#else` constructs is basically the same, modulo the constants being used.
- Hence, I've decided to inline one decision branch directly into the function as Go does not natively support pre-processor directives like `#ifdef`. 
- The functionality depending on the `UNCHECKED_BITSTREAM_READER` preprocessor directive has also been included without making it conditional, because Go has no equivalent feature. In lieu of a compile-time flag alternative, you'll want to replace these with appropriate runtime checks or configuration options.
- I added "GetBitContext" struct definition because it seems like your C structure expect this structure to be passed but it was not provided initially.  Feel free to replace with your correct structure representation.