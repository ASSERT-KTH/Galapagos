One important thing to note is translating C code to Go isn't straightforward because Go doesn't support direct memory management like C does. Here's an attempt:

go
import "crypto/big"

func BnFree(num *big.Int) {
	if num == nil {
		return
	}
	if !bnGetFlags(num, BN_FLG_STATIC_DATA) {
		BnFreeD(num, 0)
	}
	if bignumFlags & BN_FLG_MALLOCED {
		OpenSSLFree(num)
	}
}

However, this isn't semantically equivalent as hint adressed earlier:
- Memory management functions `OPENSSL_free(a)` or `bn_free_d(a, 0)` can't be written in pure Go, mostly because Go's garbage collection handles freeing memory.
- Flag operations like `BN_get_flags(a, BN_FLG_STATIC_DATA)` can't be implemented in the same manner, as there isn't such a one-to-one concept in Go against C.` BN_get_flags` is used to get flags told about the status of the `BIGNUM data`. While BIGNUM directly is not in Go, there's a similar type `math/big/Int`, but not being controlled manually such flags/control.
- After all , Go's tradeoff provides several advantanges over C, such as simplicity, garbage collection and built-in features for concurrency handling over finer memory control and potential for speed optimizations.
   
Above implementation will help in under understanding how similar pattern applied when decoding however exact translation can not be achieved because it's not viable. External ssl/bignum package has to be created with c-bindings that include own memory management of BIGNUM C liberary data. That would clearly compromise 'no auxiliary function' conditions. 

Sources:
- https://go101.org/article/memory-leaking.html
- https://github.com/tensorflow/tensorflow/pull/25139
- https://www.infoq.com/news/2020/10/secure-go-crypto-apis