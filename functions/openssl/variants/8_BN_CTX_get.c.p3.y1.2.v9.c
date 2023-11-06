Translating this function from C to Go is challenging because Bignum is implemented very diferently in the `math/big` library compared to openssl. Here is a rough approximation that simply provides a new Large Number each time and maintains the count with each instance of the context structure.

go
import (
	"errors"
	"math/big"
)

type BN_CTX struct {
	errStack bool
	tooMany  bool
	pool     *BN_POOL
	flags    int
	used     int
}

// struct holding instances of *big.Int on "request"
type BN_POOL struct {
	builder []**big.Int
	flags   int
}

// returns *big.Int from a pool and flags whether it has been previously used
func (pool *BN_POOL) get(used bool, flags int) (*big.Int, error) {
	if len(pool.builder) == 0 || used {
		return nil, errors.New("too_MANY_TEMPORARY_VARIABLES")
	}

	bn := *pool.builder[len(pool.builder)-1]
	
	pool.builder = pool.builder[:len(pool.builder)-1]
	
	return bn, nil
	
}

func BN_CTX_get(ctx *BN_CTX) (*big.Int, error) {
	if ctx.errStack || ctx.tooMany {
		return nil, errors.New("too many temporary variables")
	}
	ret, err := ctx.pool.get(ctx.used > 0, ctx.flags)
	if err != nil {
		ctx.tooMany = true
		return nil, err
	}
	//Ensures the bigNum is zero each time
	ret.SetInt64(0)
	//Increments count of used times
	ctx.used++
	return ret, nil
}
