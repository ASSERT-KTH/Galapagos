void EVP_PKEY_free(EVP_PKEY *x)
{
    int refCount;

    if (!x)
        return;

    // Decrease the reference count
    CRYPTO_DOWN_REF(&x->references, &refCount, x->lock);
    // Print current reference counter status
    REF_PRINT_COUNT("EVP_PKEY", x);

    if (refCount > 0)
        return;

    // Assertion for ensuring released resource had references
    REF_ASSERT_ISNT(refCount < 0);

    // Free any internal, implementation-specific details
    evp_pkey_free_it(x);
    
#ifndef FIPS_MODULE
    // Free an ExData item index in library context.
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
#endif

    // Free a THREAD_LOCK
    CRYPTO_THREAD_lock_free(x->lock);

#ifndef FIPS_MODULE
    // Pop all value from stack and free them
    sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
#endif

    // OpenSSl's wrapper for free (x)
    OPENSSL_free(x);
}