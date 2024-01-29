In Go, we cannot maintain the existing function signature like in C as it doesn't support pass by reference semantics for fundamental types. However, we'll have the GetBitContext variable as a part of the receiver to manipulate it inside this function definition like below. 

Again due to lack of macros in Go, the macro functions OPEN_READER, UPDATE_CACHE, SHOW_UBITS, LAST_SKIP_BITS, CLOSE_READER and av_assert2 the simple 1:1 mapping is not possible. Therefore, the assumption made is that their implementations are methods on GetBitContext type struct:

go
type GetBitContext struct {} (include your struct properties here.)

func (s *GetBitContext) getBits(n int) uint64 {
    var rev uint64
    s.openReader()
    if n)<= 0 || n >25 { panic("n is out of  bounds")} 
    s.updateCache()
    rev = s.showUBits(n)
    s.lastSkipBits(n)
    s.closeReader()
    if rev >= 1<<n { panic("rev is out of bounds") }
    return rev
}

(type GetBitContext struct {
(whatever functionalities in OPEN_READER, UPDATE_CACHE, SHOW_UBITS, LAST_SKIP_BITS, CLOSE_READER you have, should be moved to corresponding receiver function implementation on Go.)
}) 
 

Replace the methods openReader, updateCache, showUBits, lastSkipBits, closeReader according to the corresponding C macro logic.

That's the closest translation can be done from C to Go keeping macro logic in Go struct methods, but still, it's implementation might closely differ according to your macro usage in C.

Note: panic is used where av_assert2 is used since av_assert2 usually are like asserts and will stop the execution if the condition doesn't meet which is quite similar what panic does.

Also, n should be positive and shouldn't be more than 64 as uint64 is used, Go doesn't supports UINT64_C macro equivalent. Therefore bit shifting more than 64 would not make any sense:

Go
if rev >= 1 << uint(n)

The check would unfortunately likely not work if n is more than 64. 

It is important to properly refactor code to accommodate due to these sorts of incompatibilities between C and Go.