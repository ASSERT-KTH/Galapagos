Go Programming Language does not support classes or methods like C++, so this cannot have a direct equivalent function. Also, Go has distinct semantics and libraries, This makes making an exact equivalent often unfeasible. However, you can do a similar implementation:

The BIGNUM concept in Go can be mapped with big.Int.
BN_CTX could be a struct that holds a *big.Int.

Here is a simple example for comparing/illustrating certain processes with Go:

go
type BN_CTX struct {
	errStack bool
	tooMany  bool
	pool     *big.Int
	flags    int
	used     int
}

const BN_FLG_CONSTTIME = 1

func BN_CTX_get(ctx *BN_CTX) *big.Int {

	if ctx.errStack || ctx.tooMany {
		return nil
	}

	ret := new(big.Int)
	ret.Set(ctx.pool) // The line could be customized depending on the Original intend and function wise of the C approach.
	
	if ret == nil {
		ctx.tooMany = true
		log.Println("ERR_raise(...), BN_R_TOO_MANY_TEMPORARY_VARIABLES")
		return nil
	}

	ret.SetInt64(0)                   // To ensure the ret is zero

	retBits := big.NewInt(int64(ctx.flags))
	ctxNewBits := big.NewInt(int64(BN_FLG_CONSTTIME))
	ctxNegativeBits := ctxNewBits.Not(ctxNewBits)
	ret.And(retBits, ctxNegativeBits) // effectively achieve ret->flags &= (~BN_FLG_CONSTTIME)
	ctx.used++
	
	return ret
}

The means of flags and CTX (presumably custom log) functions are unknown in your context of your send C code, but this is a comparable way in Golang. Remember to meet the concept of original implementation having done in Golang.