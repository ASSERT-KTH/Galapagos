int BIO_free(BIO *b)
{
    int status;

    if (!b) 
        return 0;

    if (CRYPTO_DOWN_REF(&b->references, &status, b->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", b);
    if (status > 0)
        return 1;
    REF_ASSERT_ISNT(status < 0);

    if (HAS_CALLBACK(b)) {
        status = (int)bio_call_callback(b, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (status <= 0)
            return 0;
    }

    if ((b->method != NULL) && (b->method->destroy != NULL))
        b->method->destroy(b);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, b, &b->ex_data);

    CRYPTO_THREAD_lock_free(b->lock);

    OPENSSL_free(b);

    return 1;
}