Translating the exact code from C to Go wouldn't be proper since C and Go have different ways of performing operations. Go has its own mechanisms and approaches towards approaching the problem. However, assuming "BIO" is a struct similar to this form,

go
type BIO struct {
    references int
    lock       sync.Mutex
    method     *Method
    exData     string
}


where

go
type Method struct {
    destroy func(*BIO)
}


here is a comparable function in Go that presents a similar computation logic as the provided C function,

go
import (
    "sync"
    "crypto"
)

func BIO_free(a *BIO) int {
    if a == nil || cryptoDownRef(&a.references, &ret, &a.lock) <= 0 {
        return 0
    }

    refPrintCount("BIO", a)
  
    if ret > 0 {
        return 1
    }
  
    if hasCallback(a) {
        ret = bio_call_callback(a, BIO_CB_FREE, nil, 0, 0, 0, int64(1), nil)
        if ret <= 0 {
          return 0
        }
    } 

    if a.method != nil && a.method.destroy != nil {
        a.method.destroy(a)
    }

    crypto_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a.exData)
    sync.mutex_free(&a.lock)
  
    return 1
}


Note here, we are assuming the functions `cryptoDownRef`, `refPrintCount`, `hasCallback`, `bio_call_callback`, `crypto_free_ex_data,` and `sync.mutex_free` based on the C code. Some of these are not part of standard Go or its common packages, so we're making a certain liberty in this translation.

Also, keep in mind, null point checking given in C code `a == NULL` is equivalent to `a == nil` in Go.

Similarly, free in Golang is done by the Garbage Collector. Directly manipulating memory has a chance to be harmful in Go programming. 

This translation is module level since Go language parameters and approaches are different from C in some broad context. In a real code implementation, it requires refactoring and modifications.