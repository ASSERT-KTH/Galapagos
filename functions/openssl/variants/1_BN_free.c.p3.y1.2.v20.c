In Go, since it's garbage collected, you do not generally free objects as you'd do in C, so the translation of freeing functions is usually function-less, because objects and buffers once not referenced are automatically cleaned up by GC.

Either way, right now as far possible there is no straightaway translation because Go has it's own built-in big number package ("math/big") and OpenSSL's BIGNUM structure used in your function references an internal structure in OpenSSL library which is not directly translated into Go.
 
The bigInt in Go’s (math/big) doesn't have equivalent flags such as BN_FLG_STATIC_DATA etc.

So we just clean-up in order to avoid memory allocation of BigInt by setting it as nil after using it exactly as it is being done in OpenSSL
// If references are unset, garbage-collector will take care of them.
Given that fact; below is the skeleton translation which must fulfill the clean-up expectations in Go

go
import (
	"math/big"
)

func BN_free(a *big.Int) {
	a = nil
}

Beyond nil-ing these references in this particular method, without a more holistic view of the context in which this specific function is being used can go wrong, as garbage collection in Go will take care of dying objects, which are without references. More context might help provide a more accurate translation.