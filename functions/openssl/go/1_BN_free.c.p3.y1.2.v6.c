Go does not support equivalence to 'BN_free' directly as go's standard library does not provide complete compatibility with openSSL big number libraries. Also, in Go destructors are not required because of its automatic garbage collection which reclaims memory once there are no references to the variables anymore. 

However, if you're using third-part library `crypto/bn` for similar usage, you can write something roughly similar. Here assuming the `bn.r` receiver was pointer to "BIGNUM" which can be flagged as free or not.
Go
func (bn BIGNUM) BNfree(){
	if bn == nil {
		return
	}

	if bn.r.BNgetflags(BN_FLG_STATIC_DATA) {
		bn.r.BNfreeData(0)
	}

	if bn.r.Flags & BN_FLG_MALLOCED != 0 {
		bn.r.Clear()
    }
}


This is an illustrative example only and may not even compile as Go's stdlib/crypto does not have BIGNUM or such type defined plus there is no one-to-one match for C's OpenSSL with Go’s crypto libraries. To use Open SSL in Go, you would need to use a Cgo binding (that connect Go and C libraries) or find corresponding Go SSL or cryptography library.