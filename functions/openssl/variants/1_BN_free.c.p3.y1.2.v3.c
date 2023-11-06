Playing around with OpenSSL doesn't really make sense in go as go has a vastly different and more friendly crypto stdlib. Due to language differences, it's hard to translate this directly over, but semantically you can use Go big.Int to create equivalent integer. Due to Go has its garbage collector, we don't need to free up allocated memory manually unlike in C.

Keeping those constraints into viewing, the semantically equivalent version of your aforementioned method in Golang would be as follows. 

go
import (
    "math/big"
    "errors"
)

func FreeInt(a *big.Int) error {
    if a == nil {
        return errors.New("Int is nil")
    }
    // set the bits to zero 
    a.Set(big.NewInt(0))
    return nil
} 


Please understand that BigNumber usage in Golang is way different than C as we don't need be to be concern of allocating or freeing the memory by ourselves. Management of memory is taken by garbage collector time to time based on reachability of the object scope cycle. 

But if you really need to free only pointer(BigNum) in Go language than unfortunately you can't do manually as management of memory purely depends on the garbage collector. If you destroyed/scoped out all references to that memory, that memory will be free itself by the garbage collector on reach of Unreachable object life cycle.

Big number conversion `string -> BigNumber| BigNumber -> string`, BigNumber operations `add, sub, mul, comp, gcd etc` are readily available in go language Big number Package.

I hope above explanation along with pseudo code help you understand significant code convention&runtime changes of Golang as llvm platform languages. In Golang its hard to equivalent the exact implementation of your example in my best knowledge.