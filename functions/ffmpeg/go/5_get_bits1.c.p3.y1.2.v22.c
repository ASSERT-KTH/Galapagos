You cannot directly translate this C code into an equivalent Golang function because Golang doesn't support pointer arithmetic operations and bitwise operations are not applied in Golang in the same way. 

However, you could make a function that combines bytes to get bits in a somewhat similar way like the existing function does:

go
import "math"

var currentIndex int = 0

type GetBitContext struct {
	Buffer []byte
	Index  uint32
    SizeInBitsPlus8 uint32
}

func get_bits1(s *GetBitContext) uint8 {
	index := s.Index
	result := s.Buffer[index >> 3]
	
	if s.buffer == 1 { 
		result >>= 1 
        result &= 1 
	} else {           
	//le left unshift
        result = math.MaxUint8 & (result << (index & 7))
	//le right shift
		result >>= math.MaxUint8 - 1 
	} 
	
	if !(currentIndex > len(s.Buffer) - 1){
		index++
	}
	s.Index = index

	return uint32(result)
}

This is the closest I can get to existent function based on C version. Please note that your might need to optimize conditions and adapt this stub to your product since it's barely not feasible to make fully identical conversion due to language metamodels difference.

Also, my implementation might not cover condition "!UNCHECKED_BITSTREAM_READER" which might have important sense in a real product, for brevity and better understanding of the code, turning conditions related to unfinished operations or verification were omitted in the given golang conversion.