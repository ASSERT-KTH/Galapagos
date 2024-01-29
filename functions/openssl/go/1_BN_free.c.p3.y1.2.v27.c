The Go programming language does not allow you the same level of memory management that C does, primarily due to the automatic garbage collection making manual memory management, especially associated with pointers, unnecessary. This would refute the exact translation of the code.
However, trying to represent the logic of this function in a more general feature, one could produce something like so:

go
import "crypto/big"

func BnFree(a *big.Int) {
	if a == nil {
		return
	}
	// Go doesn't have an exact equivalent for BN_get_flags and OpenSSL flags and functions
	// If we stored data references somewhere (e.g., map) we could delete them instead of freeing memory directly

	// Some pseudo logic derived from the original function
	flags, ok := globalFlagsStore[a]
	if ok && flags != BnFlgStaticData {
		bnFreeD(a, 0)
	}
	if ok && flags == BnFlgMalloced {
		delete(globalFlagsStore, a)
	}

	// Due to garbage collection in Go, memory will be automatically freed up when there's no reference left
	// So no direct equivalent to OPENSSL_free
}

// The bnFreeD doesn't exist in Go's big package, so can't provide equivalent
func bnFreeD(a *big.Int, i int) {
	// Some logic here...
}

const (
	BnFlgStaticData = iota
	BnFlgMalloced
)

var globalFlagsStore = make(map[*big.Int]int)


This does not do what the C code does (freeing memory manually when an object was dynamically allocated), but gives an overall idea how some equivalent operation could be defined in Go.
Note that garbage collection in Go implicitly does freeing part what original C function does.