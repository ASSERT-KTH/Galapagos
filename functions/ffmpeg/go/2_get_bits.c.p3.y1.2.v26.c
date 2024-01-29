In Go, we don't have direct C-like macros or equivalent for "register" statement. Considering "OPEN_READER", "UPDATE_CACHE", "SHOW_UBITS", "LAST_SKIP_BITS", and "CLOSE_READER" as well as "av_assert2" are macro-level function or procedures in C (which Go does not support), we would need to write full-fledged functionalities to replicate their features.

Due to some language differences between C and Go, this equivalant function may need heavy modifications in a Go version with custom handling for these operations.

For instance and simplicity, let's assume that GetBitContext contains a slice of uint32 and a pointer. Handling with C's assertions and uint64 usage further assume this snippet rolls bits out fully.

go
type GetBitContext struct {
	bits []uint32
	nbit uint32
	fp   *uint32
}

// Calulating roll on bit 
func RollingBit(gbi uint64,nbit uint32) uint64  {
	var i uint32
	for i=uint32(0);i<nbit;i++{
		gbi = Getlb((gbi+nbit)>>i);
	}
	return gbi;
}

// Getting Least Bits
func Getlb(lhs uint64) uint64 {
	return lhs & uint64(UINT32_MAX);
}

func getBits(s *GetBitContext, n int) uint32 {
	
	
	if s == nil || n <= 0 || n> 32 {
		panic("Assertion condition failed.")
	}
	tmp := s.bits[*s.fp]
	
	if int(tmp) >= 1<<n {
		panic("Assertion condition failed.")
	}
	
	*s.fp += 1
	s.nbit -= uint32(n)

	return tmp
} 


However, more detailed structure for GetBitContext and helper functionality definitions are needed before bit offset operations or CONTEXT_ADJUST with elements in more complex struct designs. Configurations and implemented operations among contained structs may matter transferring all between both version, fairly normal amount of revisions / alterions / further error handling potentials expected after laying out most functionalities equivalent.