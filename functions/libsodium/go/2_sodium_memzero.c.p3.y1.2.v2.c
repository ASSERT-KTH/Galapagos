The sodium_memzero converts into the following Go code:

go
import "C" 

//export sodiumMemZero
func sodiumMemZero(pnt *C.uchar, len C.size_t) { 
	for i := C.size_t(0); i < len; i++ { 
		pnt[i] = 0
	} 
}


Note:

- Inner workings of memset are replaced with idiomatic Go.

- C type casting replaced with Go equivalents.

- For simplicity purposes, error checks (-- sodium_misuse) are removed.

- Each case for setting to zero with different methods - SecureZeroMemory, memset_s, explicit_bzero, memset_explicit, explicit_memset, have been removed as there are no direct equivalents to these system level calls in Go. Go ndard "for" has been used.

- We've stuck to minimalist operations considering Go doesn't perform inline Assembly, weak symbol references as how C inherently provides.

Remember to use Go's equivalent utility by discussing it with your Dev or DevOps Team; Go gives `cgo` utilities, unsafe package and pointer functionalities where needed. This example strictly demonstrations transformation to pure Go.

Lastly, do extensive testing as translating C to Go isn't direct one at times; there could be implicit dependency in your original program such as specific performance characteristic which might not be fulfill with this silhouette.