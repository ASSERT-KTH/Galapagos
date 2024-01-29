In Go, the equivalent function might be implemented using a structure and methods similar to this one:

Go
type BN_CTX struct {
    ErrStack   error
    TooMany    bool
    Pool       *BN_POOL
    Flags      int
    Used       int
}


type BIGNUM struct {
    Flags int
}

func (ctx *BN_CTX) Get() *BIGNUM {
    // Default to returning nil on "TooMany" and if ErrStack is set
    if ctx.ErrStack != nil || ctx.TooMany {
        return nil
    }

    ret := ctx.Pool.Get(ctx.Flags)

    // If no "ret" block is found, "TooMany" is set to prevent future attempts
    if ret == nil {
        ctx.TooMany = true
        return nil
    }

    // Reset flags to 0 for each bignum returned  
    ret.Flags = 0
                        
    // Increment the usage count for the pool of bignums                   
    ctx.Used++

    return ret
}

Please note that it isn't exact conversion of the references  C code `BN_zero(ret);` & `ret->flags &= (~BN_FLG_CONSTTIME);` due two reasons:

1. C and Go manage memory and clear variables in different ways.
2. Unknown operations and definitions in the C code (such as the `BN_zero` and `~BN_FLG_CONSTTIME` operation). Assuming default initializations due to lack of context. 

Also note base64 reversing at the start has been ignored, because it wasn't possible to explicitly determine purpose without further context.