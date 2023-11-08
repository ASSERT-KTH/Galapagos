Variant 1:

int BIO_free(BIO *a) 
{
    if (!a)
        return 0;

    int ret;
    if (!CRYPTO_DOWN_REF(&a->references, &ret, a->lock))
        return 0;
    
    REF_PRINT_COUNT("BIO", a);
    if (ret) return 1;
    REF_ASSERT_ISNT(ret < 0);

    if (HAS_CALLBACK(a)) {
        if((ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL)) <= 0)
            return 0;
    }

    if (a->method && a->method->destroy)
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
    CRYPTO_THREAD_lock_free(a->lock);
    OPENSSL_free(a);

    return 1;
}

Variant 2:

int BIO_free(BIO *a) 
{
    int ret;
    if (!a || !CRYPTO_DOWN_REF(&a->references, &ret, a->lock))
        return 0;

    REF_PRINT_COUNT("BIO", a);
    if (ret > 0) return 1; 
    REF_ASSERT_ISNT(ret < 0);

    if (HAS_CALLBACK(a)) {
        ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (ret <= 0) return 0;
    }

    if (a->method && a->method->destroy)
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
    CRYPTO_THREAD_lock_free(a->lock);
    OPENSSL_free(a);

    return 1;
}


Variant 3:

int BIO_free(BIO *a) 
{
    if(a == NULL) 
        return 0;

    int ret;
    if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0) 
        return 0;
    
    REF_PRINT_COUNT("BIO", a);
    if(ret > 0) 
        return 1;

    REF_ASSERT_ISNT(ret < 0);
    
    if (HAS_CALLBACK(a)) {
        if((ret = bio_call_callback(a, BIO_CB_FREE, nullptr, 0, 0, 0L, 1L, nullptr)) <= 0)
            return 0;
    }

    if(a->method != NULL && a->method->destroy != NULL)
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    if(a->lock != NULL)
        CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return 1;
}