go
type GetBitContext struct {
    index              uint
    sizeInBitsPlus8    uint
    buffer             []byte
}

func getBits1(s *GetBitContext) uint {
    index := s.index
    result := s.buffer[index>>3]
    
    if isBitstreamReaderLE() {
        result >>= index & 7
        result &= 1
    } else {
        result <<= index & 7
        result >>= 8 - 1
    }
    
    if !isUncheckedBitstreamReader() && s.index < s.sizeInBitsPlus8 {
        index++
    }
    
    s.index = index
    
    return uint(result)
}

Notes:
1. I have made an assumption that countFromLeft and unCheckBitstreamReader are act like preprocessor directives. I am using two go functions to act in place of that directive to show you an alternative way to handle this that will compile completely, I expect you to prefer something like closing (#else or #endif) to get functional equivalent output. You need to replace options(isBitstreamReaderLE and isUncheckedBitstreamReader) with your requirement options.
2. The Go doesn't supportoperation on bitwise base, so you may reimplement shifting on base what you need. Thus, you can see #ifdef and #endif like translation phrases in C has been applied yet explicitly recognizable from a sub-statement incase of Go version of function.