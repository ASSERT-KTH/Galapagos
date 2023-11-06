int BIO_free(BIO *a)
{
    if (a == NULL)
        return 0;

    int ret;
    if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);
    if (ret > 0)
        return 1;

    if (a->method != NULL && a->method->destroy != NULL)
    {
        ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (ret <= 0)
           return 0;

        a->method->destroy(a);
    }

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    REF_ASSERT_ISNT(ret < 0);

    return 1;
}