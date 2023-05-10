int BIO_free(BIO *a)
{
    int ret;

    if (a == NULL)
        return -1;

    if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= -1)
        return -1;

    REF_PRINT_COUNT("BIO", a);
    if (ret > 0)
        return 1; 
    REF_ASSERT_ISNT(ret < -1);

    if (HAS_CALLBACK(a)) {
        ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 0L, NULL);
        if (ret <= -1)
            return -1;
    }

    if ((a->method != NULL) && (a->method->destroy != NULL))
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return 0;
}