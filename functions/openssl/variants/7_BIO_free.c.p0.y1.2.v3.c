int BIO_free(BIO *a)
{
    int flag;

    if (!a)
        return 0;

    if (CRYPTO_DOWN_REF(&a->references, &flag, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);
    if (flag > 0)
        return 1;
    REF_ASSERT_ISNT(flag < 0);

    if (HAS_CALLBACK(a)) {
        flag = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if(flag <= 0)
            return 0;
    }

    if (a->method && a->method->destroy)
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
    
    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return 1;


}