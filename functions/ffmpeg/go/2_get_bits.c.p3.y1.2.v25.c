Without a clear declaration of the specific C macros (a preprocessor which allows the loader to perform actions at compile time by directive communication), structs or libraries the original function uses it's difficult to create a precise equivalent code, since C and Golang do too have very different approaches to achieving certain tasks and Golang doesn't have the exact same concepts.

However, based on my assumptions from your original code, I can provide this rough equivalent in Go assuming the `GetBitContext` was some sort of context housing bytes etc, following operations can be mapped:

- 'OPEN_READER': We are initialising/setting up the reader 're'.
- 'UPDATE_CACHE': Maybe it's somewhere there are some still there are some buffered data.
- 'SHOW_UBITS': Probably it is reading certain number of bits 'n'.
- 'LAST_SKIP_BITS': It seems to remove or ignore certain bits (n) from the stream after their information was / should been used.
- 'CLOSE_READER': Perhaps it's some logic to wrap/cleanup or teardown.

Here's Go sample of your code:

go
const MaxUint = ^uint(0)
const MaxInt = int(MaxUint >> 1)

type GetBitContext struct {
	// Add your structure definition here
}

func getBits(s *GetBitContext, n int) uint {
	if n <= 0 || n > 25 {
		panic("n is out of range! Should be in 1 to 25!")
	}

	re := iniReader(s)
	tmpArr.err := re.Read(s)

	if err != nil {
		panic(err)
	}

	tmpUInt := bytes2Int(tmpArr)
	re.skipBits(s, n)

	if tmpUInt >= (1 << uint(n)) {
		panic("tmp is out of bounds! Should be less than 1 __shifted_left_by__ n!")
	}

	     // change structure of what you wanted
	return tmpUInt
}


Because in golang no reference is used and has Garbage collection, as well unlike c which needs to close or destroy. For function and macro names guessing what they did as we don't have their definitions and golang don't directly support macros. 

C checks with assert, while Go tend to execution fall having a zero value for an undefined / un-initialized variable exists.

As pointers aren't displayed in shell and OPEN/UPDATE/Show/Last/CLOSE I've reimagined into Go equivalent code, while needed please replace the structure what you wanted. 

If you require more exact translated code, you would need to provide minimum working example with additional C function macros defined such as `OPEN_READER`, `UPDATE_CACHE`, `SHOW_UBITS`, `LAST_SKIP_BITS`, and `CLOSE_READER`.