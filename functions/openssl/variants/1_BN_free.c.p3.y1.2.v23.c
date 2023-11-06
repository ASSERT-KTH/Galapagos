There is no direct translation of this function from C to Go, because the language constructs are fundamentally different. RFC, or really big int type, handled here through C pointers, can be managed in Go through Go's big package with big.Int type without direct memory manipulation as in the C code.

This is as close as you can get in translating the given function, but:

- You have to replace OpenSSL function calls with the appropriate library in Go.
- You need to add checks for dynamic allocation and check for static in another way, since that is not quite possible in Go in the way it's done in C.
- Do replace liberties like “BIGNUM”, “BIGFLG_STATIC_DATA”, “bn_free_d”, and “OPENSSL_free” with what is appropriate in your Go code. 

Illustrating structure and pointer workings:

go
type BIGNUM struct {
    n big.Int
    FLG_STATIC_DATA bool
    MALLOCED bool
}

func BN_free(a *BIGNUM) {
    if a == nil {
        return
    } else if !a.FLG_STATIC_DATA {
        // Perform equivalent to bn_free_d
        // There's no direct equivalent to "bn_free_d" and "OPENSSL_free" in Go. 
        // You should use the appropriate Go code or library to deallocate 
        // or manually release any resources if necessary.
    }
    
    if a.MALLOCED {
        // Equivalent to OPENSSL_free
        a = nil
    }
}


Start by structuring your high-level application with idiomatic Go practices re ‘values and pointers,’ object’s (and here dynamic/higher sizes thereof at Big library’s service) practices.