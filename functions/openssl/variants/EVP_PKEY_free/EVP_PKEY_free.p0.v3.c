void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    if (x == NULL)
        return;

    i = _Atomic_load_x(&x->references, memory_order_relaxed);    
    do {
        if (i <= 0)
            return;
    } while (!_Atomic_compare_exchange_weak_x(&x->references, &i, i-1, memory_order_acquire, memory_order_relaxed));
    REF_PRINT_COUNT("EVP_PKEY", x);
    if (i > 1)
        return;
    
    evp_pkey_free_it(x);
#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
#endif
    CRYPTO_THREAD_lock_free(x->lock);
#ifndef FIPS_MODULE
    sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
#endif
    OPENSSL_free(x);
}