The Go language has garbage collection and does not normally require explicit memory deallocation. However, the provided code is freeing up some explicit locks and reference count which may depend upon specifically how your EVP and CRYPTO data structures are created in Go and other possible dependencies. Here is an attempt to recreate the C function in Go, but actual implementation can significantly differ based on how the data structures and several calls, not present in Go standard library, are handled in your Go environment.

Please note, without more information about the external methods and data structures referred to in your C code, creating a direct translation is not really feasible. The below is just a rough guess.  

Go
func EVP_PKEY_free(x *EVP_PKEY)  {
    var i int

    if x == nil  {
        return
    }

    x.references, i, x.lock = CRYPTO_DOWN_REF(x.references, i, x.lock)
    REF_PRINT_COUNT("EVP_PKEY", x)
    if i > 0 {
        return
    }
    if i < 0 {
    	panic("i shouldn't be smaller than 0")
    }
    x = evp_pkey_free_it(x)
  
    x.ex_data = CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, x.ex_data)
    
    x.lock = CRYPTO_THREAD_lock_free(x.lock);

    for index := range x.attributes {
        x.attributes[index] = X509_ATTRIBUTE_free(x.attributes[index])
    }

    x = nil
}

This function does not carry many semantic similarities to the C function passed, as Go standard library does not have methods directly correlating to the functionality provided by those used in the passed C function.

Explicit use of C code in Go code is possible using "C" pseudo package, but it often needs cgo utility. Also using defer for dealing with exceptions or recover to emulate the C to Go go-unimplemented behaviours is common. All these would require distribution of C libraries and could prove unnecessary complex for such tasks.

Therefore, most idiomatic Go software would avoid the situations which require explicit memory dealing or would use a finalizing method to deal various cleanup activities during garbage collection. Regex pattern replacements would be better done using native Go functionality capable of returning errors or dedicated regex processing libraries. And complex uses of locks and thread would be handled through native Go routines, channels, sync package and possibly context package which provide a great deal of simplifications over threading functionality available in traditional C like methods.