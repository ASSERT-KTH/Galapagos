The Go programming language is much different than C and does not support manual and direct memory management handled by the above code and semantics of function calls, and parameter handling are very different. It's even complicated further as no details were given about individual functions, but favoring similar structure, it may look something like this (with extensive modifications):

go
import (
	"sync"
	"errors"
	opensslex "github.com/OpenSSL-go-example"
)

type BIO struct {
    ...
}

// Returns error on failure, otherwise nil
func BIOFree(b *BIO) error {
	if b == nil {
		return errors.New("b is nil")
	}

	if err:= opensslex.CryptoDownRef(...)
		return err;

	ret, err:= BIOCallback(...)
    if err != nil || ret <=0 {
        return errors.New("callback error")
	}

    /* Here binary.Method represents a disruption function for B
    * This is hypothetical as we don't have the original source to reference to
	*/
	if b.Method != nil && b.Method.Destroy != nil {
		b.Method.Destroy(b)
	}

    opensslex.CryptoFreeExData(INPUT_ARGUMENTS ...)

	TerminateLock(b.LOCk_ARGS ...)

	ret := opensslFree(b)
	if ret < 1 {
		return errors.New("Failed in freeing memory B")
	}
    
    return nil
}

In Go, Bad practice to directly return any numbers (like 0,1 as it was done in the given C code), instead Errors are used.

The contents represented between elipse (...) in our code denotes the input arguments which can be directly evaluated or filled based on context because for functions like CryptoDownRef and we aren't provided with the reference where these functions are implemented.

This translates to roughly the same workflow as the C implementation. Further accuracy can obtained if a full view replica if the original BIO can be recreated.