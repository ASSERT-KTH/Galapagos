Here is a conversion of the provided code into Go:

go
type GetBitContext struct{ /*... context structure details ...*/ }

func getBits(s *GetBitContext, n int) uint32 {
	var tmp uint32

	// Assuming OPEN_READER and other macros functions exists 
	// as different functions in Go
	re := OpenReader(s)
	
	if !(n > 0 && n <= 25) {
		panic("n must be > 0 and <= 25")   //equivalent to av_assert2 in c
	}

	UpdateCache(&re, s)
	tmp = ShowUBits(&re, s, n)
	LastSkipBits(&re, s, n)
	CloseReader(&re, s)

	// Value of UINT64_C(1) in Go for assert
	valueToCheck := uint64(1) << uint32(n)
	if uint64(tmp) >= valueToCheck {
		panic("tmp must be lower than 2 ^ n") //equivalent to av_assert2 in c, ideally should use some Go assertion package
	}
	
	return tmp
}


This code involves a conversion into go and as go does not support macros, one would need to check what operations OPEN_READER, UPDATE_CACHE, SHOW_UBITS, LAST_SKIP_BITS and CLOSE_READER do in C and create a corresponding function in Go, since Go does not support those semantics directly.