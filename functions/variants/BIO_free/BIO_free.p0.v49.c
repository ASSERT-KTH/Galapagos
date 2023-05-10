int BIO_free(BIO *a)
{
    int ret;

    if (!a)
        return 0;

    if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);
    if (ret > 0)
        return 1;
    REF_ASSERT_ISNT(ret < 0);

    if (IS_CALLBACK_PASSED(a)) {
        ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (ret <= 0)
            return 0;
    }

    if ((a->method != NULL) && (a->method->destroy != NULL))
        a->method->destroy(a);

    CRYPTO_free_EX_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_unlock_free(a->lock);

    OPENSSL_clean(a);

    return 1;
}