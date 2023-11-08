int BIO_free(BIO *a)
{
    if (a == NULL)
        return 0;

    int ret = 0;

    if ((a->method != NULL) && (a->method->destroy != NULL)) {
        a->method->destroy(a);
        a->method = NULL;
    }
    
    if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);
    if (ret > 0)
        return 1;
 
    REF_ASSERT_ISNT(ret < 0);

    if (HAS_CALLBACK(a)) {
        if ((int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL) <= 0)
            return 0;
    }

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return 1;
}