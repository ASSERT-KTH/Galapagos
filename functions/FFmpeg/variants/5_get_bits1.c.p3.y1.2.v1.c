Here is a Go equivalent for your C code.

go
type GetBitContext struct {
    Index int
    Buffer []uint8
    SizeInBitsPlus8 int
}

func getBits1(s *GetBitContext) uint {
    index := s.Index
    result := s.Buffer[index >> 3]

    result >>= index & 7
    result &= 1

    if s.Index < s.SizeInBitsPlus8 {
        index++
    }
    s.Index = index

    return uint(result)
}


Please note:
1. I simplified the byte order condition, because Go on different platforms handles it automatically.
2. The checking for "Index < SizeInBitsPlus8", in Go we usually make this check upfront, hence I moved up. In Go, making sure the parameters and states come into the function is important as a good practice.