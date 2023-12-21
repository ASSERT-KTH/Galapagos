It's very hard to provide an equivalent conversion of this function from C to Go, as it's leveraging a range of C only and specifically libav macros and functions such as `GET_CACHE`, `LAST_SKIP_BITS`, `SHOW_UBITS`, `UPDATE_CACHE`, `OPEN_READER` and `CLOSE_READER`. Without the implementation details for those methods, it is impossible to convert those specific functions into Go equvivalents.
Also, a valid Go translation would probably require leveraging interfaces and pointers depending on how `GetBitContext` is intended to function, and Go doesn't use a direct equivalent to the static inline pattern from C or have the registers keyword used here.    

But here is the naive form of converted function. But you need actual translation and usage of `av_assert2`, `OPEN_READER`, `UPDATE_CACHE`, `SHOW_UBITS` , `LAST_SKIP_BITS`, `CLOSE_READER` functions which is not possible without the initial implementation details.

Go
type GetBitContext struct {
   // requires structure definition
}

const (
	UINT64_C = uint64(1)
)

func get_bits(s *GetBitContext, n int) uint32 {
	tmp := uint32(0)
	
	if  n > 0 && n <= 25 {
           // OPEN_READER()
           // UPDATE_CACHE()
           //tmp = SHOW_UBITS() 
           // LAST_SKIP_BITS() 
           // CLOSE_READER()
           if tmp < uint32(UINT64_C << uint(n)) {
	        return tmp 
	   } 
	}

	return 0
}
