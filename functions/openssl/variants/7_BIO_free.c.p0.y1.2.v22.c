int BIO_free(BIO *b)
{
    int retval;

    if (b == NULL)
        return 0;

    if (CRYPTO_DOWN_REF(&b->references, &retval, b->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", b);
    if (retval > 0)
        return 1;
    REF_ASSERT_ISNT(retval < 0);

    if (HAS_CALLBACK(b)) {
        retval = (int)bio_call_callback(b, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (retval <= 0)
            return 0;
    }

    if ((b->method != NULL) && (b->method->destroy != NULL))
        b->method->destroy(b);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, b, &b->ex_data);

    CRYPTO_THREAD_lock_free(b->lock);

    OPENSSL_free(b);

    return 1;
}