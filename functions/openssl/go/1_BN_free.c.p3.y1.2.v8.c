In Go, freeing memory is handled in background by Go garbage collector and it's not common to manually manage memory like in C, but here is a semantically similar function.

Remember that the Go's garbage collector allocates the memory when you refer a certain object, struct... Once you're programmed the variable or the object to no longer refer to that memory (by setting it's pointer to nil), the garbage collector will automatically remove the memory at certain point.

Go
import (
    "crypto/big"
    "unsafe"
)

type BNfreeFlag int

const (
    BN_FLG_MALLOCED BNfreeFlag = 1 << iota
    BN_FLG_STATIC_DATA
)

type BIGNUM struct {
    number *big.Int
    flags  BNfreeFlag
}

func BN_get_flags(a *BIGNUM, flag BNfreeFlag) bool {
    return a != nil && a.flags&flag != 0
}

func BN_free(a *BIGNUM) {
    if a == nil {
        return
    }
    if !BN_get_flags(a, BN_FLG_STATIC_DATA) {
        a.number = nil
    }
    if BN_get_flags(a, BN_FLG_MALLOCED) {
        // unsafe operation
        unsafe.Pointer(a.number) = nil
        a = nil
    }
}

Note that there’s no equivalent in Go for the `BN_free` part that uses OpenSSl, as openssl utilises C dynamic memory approach which is different from Go. I've concluded it with resetting the pointer values to `nil`, by going this way allows Golang's garbage collector to regain memory from this object but its highly irregular in Golang's context.