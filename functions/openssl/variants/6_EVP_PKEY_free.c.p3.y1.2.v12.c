In GoLang but we rely on Go's garbage collector for memory management and no concept of Keys like the EVP, bso attempting a direct conversion wouldn't achieve the original C's functionality. However If we did want to write a similar sort of the function, it might look along these lines:

type EVP_PKEY struct {
    references *int
    lock *Locker
}

func (x *EVP_PKEY) Free() {
    var i int

    if x == nil {
        return
    }

    cryptoDOWN_REF(&x.references, &i, x.lock)    // Create your implementation of this function
    REF_PRINT_COUNT("EVP_PKEY", x)  // Create your own implementation of this function
    if i > 0 {
        return
    }
    REF_ASSERT_ISNT(i < 0)   // Create your own implementation of this function

    evp_pkey_free_it(x)       // Also I couldn't be able find go equivalent of these from any go library.

    // Golang lets garbage collector do the deallocation

    // Not actual Go equivalent (GC and defer make the exact equiv deprecated):
    // crypto_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data)   Implement your own function
    // golang takes care of freeing memory - nothing to dealocate here (x->lock)
    // sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free)   creating your own function
   // There's no need to free variables manually because garbage collection is automatic in Go
}
This primarily relies on replacing explicit memory de-allocation methods with equivalent Golang constructs.

However without fully understanding CRYPTO_BUILD macros and rewire it's towards golang libraries or your own custom functions, you can't properly write a equivalant code of that EVP_PKey_free(). You might need to write OpenSSL's EVP module using native golang(Calling and interacting between c and GO is also possible in golang), or else to use crypto libraries GOLANG provides natively, or another third party library which suits for GOLANG ecosystem.