
int BIO_free(BIO *a)
{
    int ret;

    if (!a)
        return 0;

    if (CRYPTO_DOWN_REF(&(a->references), &ret, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);

    if (ret > 0)
        return 1;

    REF_ASSERT_ISNT(ret < 0);

    if (HAS_CALLBACK(a)) {
        int callback_refl = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (callback_refl <= 0)
            return 0;
        ret = callback_refl;
    }

    if ((a->method != NULL) && (a->method->destroy != NULL)) {
        a->method->destroy(a);
    }

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);
    
    OPENSSL_free(a);

    return 1;
}



int BIO_free(BIO *a)
{
    int ret;

    if (a == NULL)
        return 0;

    if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);

    if (ret > 0)
        return 1;
        
    if (ret < 0)
        REF_ASSERT_ISNT(1);

    if (HAS_CALLBACK(a) && (ret = 
       (int)bio_call_callback(a, BIO_CB_FREE, NULL, ((size_t)0), ((size_t)0), 0L, 1L, NULL)) <= 0)
        return 0;

    if (a->method && a->method->destroy)
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return 1;
}
