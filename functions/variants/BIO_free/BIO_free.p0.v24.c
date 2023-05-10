int BIO_free(BIO *a)
{
    int ret, result;

    if (a == NULL)
        return 0;

    if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);
    if (ret > 0)
        result = 1;
    else {
        REF_ASSERT_ISNT(ret < 0);

        if (HAS_CALLBACK(a)) {
            ret = bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
            result = ret > 0 ? 1 : 0;
        }
        else
            result = 1;

        if (result && (a->method != NULL) && (a->method->destroy != NULL))
            a->method->destroy(a);
    }

    if (result) {
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

        CRYPTO_THREAD_lock_free(a->lock);

        OPENSSL_free(a);
    }

    return result;
}