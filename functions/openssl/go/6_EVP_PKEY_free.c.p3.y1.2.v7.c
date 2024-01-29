Due to differences between Go and C, creating an exact semantic equivalent might be impracticable when translations are concerned and some libraries or function used in C doesn't exists at all in Golang and vice-versa, but here's how one could write a similar program disregarding crypto libraries that do not exist in Go.

In place of pointer analysis that is used in original C implementation for NULL reference check (i.e. in Go NIL reference), noop or error would suffice.

go
type EvpPkey struct {
    references int
    lock       *Lock
    // assume there is Lock structure
    exData     *CryptoExData
    // assuming we have CryptoExData and Crypto_INDEX_EVP_PKEY is some global constant
    attributes []Attribute
    // assuming we have a list of attributes
}

func EvpPkeyFree(x *EvpPkey) {
    if x == nil {
        return
    }

    // Just a mock reduce function.
    cryptoDownRef(&x.references, &x.lock)
    
    i := x.references
    refPrintCount("EVP_PKEY", x)
    // assuming refPrintCount defined elsewhere in code

    if i > 0 {
        return
    }

    assertIsnt(i < 0)
    evpPkeyFreeIt(x)
    cryptoFreeExData(EVPPKEY, x, &x.exData)

    x.lock = nil

    x.attributes = nil
    x = nil
}


The function `cryptoDownRef` / `cryptoFreeExData` / `assertIsnt` / `evpPkeyFreeIt` do not exist in Go standard library. They are part of OpenSSL in C and there's no direct analogy in Go. However the method implementations still can be written if more business cases are specified and are assumed just for closer analogy to original given C code.