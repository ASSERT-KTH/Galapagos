Unfortunately, the provided code relies on features (specifically pointers to multiprecision numbers (BIGNUM) and related functions) within the OpenSSL cryptographic library written in C programming language that aren't alternative representable in pure Golang.

However, we can leverage *big.Int in Go's math library for operations on big numbers, and the code will look like this:

go
import "math/big"

func BnFree(a *big.Int) {
  if a == nil {
    return
  }
  a = big.NewInt(0) // setting the value to zero in order to release
}

Above, `big.NewInt(0)` effectively 'releases' the big number by setting its value to zero, but Go's garbage collector manages memory allocation/de-allocation dynamically.

Note: Go's features and abilities differ vastly from C/C++. Memory management works differently. Therefore, flags such as `BN_FLG_STATIC_DATA` and `BN_FLG_MALLOCED` and operations like OPENSSL_free() don't really have exact matches in Go and this Go-code doesn't check those flags or push any data to direct GC management equivalent to a OPENSSL free equivalent.