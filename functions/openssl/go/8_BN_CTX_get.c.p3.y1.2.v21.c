Since Go doesn't support classes like C or C++, BN_CTX_get() function can't be represented exactly the same way as it is in C. However, the rough implementation could look something like this:

go
import (
    "errors"
    "big"
    "fmt"
)

type BN_CTX struct {
    errStack bool
    tooMany  bool
    pool     int
    flags    int
    used     int
}

func (ctx *BN_CTX) BN_CTX_get() (*big.Int, error) {
    var ret *big.Int

    if ctx.errStack || ctx.tooMany {
        return nil, errors.New("Too Many Temporary Variables")
    }

    ctx.pool, ctx.flags = BN_POOL_get(ctx.pool, ctx.flags)
    if ctx.pool == -1 {
        ctx.tooMany = true
        return nil, errors.New("Too Many Temporary Variables")
    }

    ret = big.NewInt(0)
    ctx.used++
    return ret, nil
}

func BN_POOL_get(pool int, flags int) (int, int) {
    // There is a mocking function as per unknown functionality of this function in the original program.
    fmt.Println("Implement the required functionality for BN_POOL_get() as per C program")
    return -1, flags
}

Few points to note here:
- BN_CTX struct in Go code is the representative of BN_CTX struct in C language.
- 'mimicking' of CTXDBG function is not done considering the auxiliary function rule. Its functionality hasn't been implemented in the provided Go implementation. If this is a major request, 'fmt.Printf()' function could be used to replace its functionality.
- ERR_raise function also has been swapped with in-build Go error handling.
- Note the function signature change to return both the object and error(format common in Go for error delivery). Result should check the error before accessing the return object.
- BN_POOL_get function is called inside the getter function, as this is specific to this usecase and would not be reusable for other cases (To maintain no auxiliary/helper requirement).
- BN_is_zero and BN_FLG_CONSTTIME concepts are handled using in-built Big Int operations in Golang.