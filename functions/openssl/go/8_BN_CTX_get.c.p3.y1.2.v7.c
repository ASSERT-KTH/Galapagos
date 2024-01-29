In Go(lang), there's no direct equivalent for C's BIGNUM data type, but Go does provides the 'big' package that we can utilize for this translation.

Here's the equivalent Go code would be something like this, given the necessary Go equivalents for the C structures, enums, and functions in question:

go
import "math/big"

type BN_CTX struct {
    errStack   bool
    tooMany    bool
    pool       *BN_POOL
    flags      int
    used       int
}

type BN_POOL struct{}

type ERROR_LIBS int
type BN_FLAGS int

const (
    ERR_LIB_BN ERROR_LIBS = iota // 0
)

const (
    BN_R_TOO_MANY_TEMPORARY_VARIABLES BIGNUM_MESSAGES = iota // 0
    BN_FLG_CONSTTIME                                          // 1
)

func BN_POOL_get(ctx BN_POOL, flags int) *big.Int {
    // ... Implementation not provided...
}

func ERR_raise(lib ERROR_LIBS, reason BIGNUM_MESSAGES) {
    // ... Implementation not provided...
}

func BN_CTX_get(ctx *BN_CTX) *big.Int {
    enterBNCTXGetter(ctx)

    if (ctx.errStack || ctx.tooMany) {
        return nil;
    }

    ret := BN_POOL_get(ctx.pool, ctx.flags)
    
    if ret == nil {
        // Setting tooMany prevents repeated "get" attempts from cluttering the error stack.
        ctx.tooMany = true;
        ERR.raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return nil;
    }
    
    // OK, make sure the returned bignum is "zero"
    ret.Set(big.NewInt(0))
    
    // Clear BN_FLG_CONSTTIME if leaked from previous frames
    ctx.flags &= ^int(BN_FLG_CONSTTIME) 
    ctx.used++
    
    leaveBNCTXGetter(ctx)
    return ret;
}


Note: 

1. I've followed <here> for enum type conversions reference where instead of enumeration, I've used each value as a distinct constant.
  
2. `enterBNCTXGetter` and `leaveBNCTXGetter` are dummy functions created to serve as placeholders for the `CTXDBG` calls in the original code.

Please adjust the function and data types according to the real logic of the software produced. This sample code may need modifications according to the actual package directory structure and variable types of your Golang project.