int BIO_free(BIO *a)
{ 
    int ret, result = 0;

    if (a == NULL)
        return result;

    if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0)
        return result;

    REF_PRINT_COUNT("BIO", a);
    if (ret > 0) {
        result = 1;
        return result;
    }
    REF_ASSERT_ISNT(ret < 0);

    if (HAS_CALLBACK(a)) {
        ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (ret <= 0)
            return result;
    }

    if ((a->method != NULL) && (a->method->destroy != NULL))
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    result = 1;
    return result;
}