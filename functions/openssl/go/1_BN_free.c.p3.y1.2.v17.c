Since Go does not support classes and hence not provide a direct equivalent of C pointers, achieving full semantic equivalence is technically impossible. For preparing the equivalent function in Go, it can be assumed that `BIGNUM` refers to a struct equivalent in Go.

Nevertheless, please find the pseudo code version using Go-style syntax as below: 

Go
import(
   "math/big"
)

func BN_free(a *big.Int) {
   if a == nil {
      return
   } 
   
   if !BN_get_flags(a, BN_FLG_STATIC_DATA){
       bn_free_d(a, 0)
   }
   
   if a.flags & BN_FLG_MALLOCED {
      *a = big.Int{}
   }
}


Notice:

- We imported the `"math/big"` package to use the `big.Int` data type, which would be best analogous to BIGNUM.

- For checking flags `BN_FLG_STATIC_DATA` and `BN_FLG_MALLOCED`, in _Go_ the `flags` field of `a` (struct of type`big.Int`) would be required. Since there is no such property for `big.Int` in standard library, I imagined that these are also defined in codebase somewhere.

- In last condition, to free memory of `a`(Kind of analogy of `OPENSSL_free(a);`), we just pointing `a` to a new memory address (this can automatically garbage collect the memory that `a` originally pointed to).

These drastically oversimplify the semantics (mainly memory-management related semantics) in the given C code. So in all cases, please take the Go code in context of C code and not as standalone equivalent code. Converting this code to a pure Go equivalent will certainly involve much restructuring and possibly a rethink of the original design.