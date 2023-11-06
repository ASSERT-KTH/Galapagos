int BIO_free(BIO *a)
{
    int ret;

    if (!a)
        return 0;

    ret = CRYPTO_DOWN_REF(&a->references, &ret, a->lock);
    if (ret <= 0)
        return 0;

    if (ret <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);
    if (ret > 0)
        return 1;

    if (ret < 0)
        REF_ASSERT_ISNT(1);

    if ((bio_call_callback != NULL) && HAS_CALLBACK(a)) {
        ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (!ret)
            return 0;
    }

    if (a->method && a->method->destroy)
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    if (a->lock)
        CRYPTO_THREAD_lock_free(a->lock);

    if (a)
        OPENSSL_free(a);

    return 1;
}