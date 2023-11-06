In Go, there are no classes, so features like methods and properties on objects do not translate directly. Also, Go does not support error handling like C; instead it returns an error as an additional return value. Hence, the parameters and returns are not exactly the same. Here is an attempt to translate:

go
package main

import (
  "errors"
  "math/big"
)

type BN_CTX struct {
  errStack, tooMany bool
  flag int
  used int
  pool chan *big.Int
}

func (ctx *BN_CTX) Get() (*big.Int, error) {
  if ctx.errStack || ctx.tooMany {
    return nil, errors.New("Either 'errStack' set, or 'tooMany' is set")
  }
  select {
    case ret := <-ctx.pool:
      zeroBigInt := big.NewInt(0)
      ret.Set(zeroBigInt)
      /* Handle flags and used here - 
       the actual masking for flag removal is left out 
       because it is highly context dependent */
      ctx.used++
      return ret, nil
    default:
        ctx.tooMany = true
        return nil, errors.New("Too many temporary variables (BN_POOL_get returned NULL)")
    }
}


Notes on the translated function:
- The C function mutates the errStack property and sets errors contextually. Instead, the Go function returns an error by convention.
- Go does not support bitwise operations on bools. Alternative implementation must depend on the semantics of the errStack and tooMany properties.
- The big Int obtaining has been modeled with a select statement and a channel.
- The C feature of setting ret to "zero" is adapted to Go syntax. If the C feature does anything beyond assigning zero, it should be implemented accordingly.
- Addressing BN_FLG_CONSTTIME is omitted because how Go could implement it is context dependent.