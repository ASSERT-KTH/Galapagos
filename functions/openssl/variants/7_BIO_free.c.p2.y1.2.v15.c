int BIO_free(BIO *a)
{
    int ret;

    if(!a)
        return 0;

    if (!(CRYPTO_DOWN_REF(&a->references, &ret, a->lock) > 0))
        return 0;

    if(!ret)
        REF_ASSERT_ISNT(false);
    else
    {
        REF_PRINT_COUNT("BIO", a);
        return 1;
    }

    if (a->callback != NULL) 
    {
        ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (!(ret > 0))
            return 0;
    }

    if ((a->method) && (a->method->destroy))
        a->method->destroy(a);

    if(a->lock != NULL)
        CRYPTO_THREAD_lock_free(a->lock);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
    
    if(a != NULL) 
        OPENSSL_free(a);

    return 1;
}