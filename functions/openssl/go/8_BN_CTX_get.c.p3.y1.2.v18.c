Here's a simplified version of your function translated into Go however it's important to know that Go cryptography libraries usually doesn't use the same object-oriented style that OpenSSL could have and Go handle errors differently:

go
func BN_CTX_get(ctx *BN_CTX) *big.Int {
    if ctx.errStack || ctx.tooMany {
        return nil
    }
 
    ret, _ := ctx.pool.Get(ctx.flags)
 
    if err != nil {
        ctx.tooMany = true
        return nil
    }
 
    ret = big.NewInt(0)
    ctx.used++
		return ret
}


In this sample, several things have not been handled because:

- ERR_raise doesn't exist in Go
- CTXBG is presumably debug related and Go doesn't really works that way
- BN_bignum types looks like actually complex types and you can't keep those kind as such and so on
More specifications would require deeper understanding of ideas behind original function also understanding `BN_POOL` struct and `Get` function, constants and structure used in entire function.

This mimics the behavior you have demonstrated in your C code however an underlying big number libraries will need to be adapted properly to implement equivalent operation in go language.
