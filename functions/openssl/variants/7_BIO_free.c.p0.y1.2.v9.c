int BIO_free(BIO *b)
{
    int Result;

    if (!b) 
        return 0;

    if (CRYPTO_DOWN_REF(&b->references, &Result, b->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", b);
    if (Result > 0)
        return 1;
    REF_ASSERT_ISNT(Result < 0);

    if (HAS_CALLBACK(b)) {
        Result = (int)bio_call_callback(b, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (Result <= 0)
            return 0;
    }

    if (b->method && b->method->destroy)
        b->method->destroy(b);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, b, &b->ex_data);

    CRYPTO_THREAD_lock_free(b->lock);

    OPENSSL_free(b);

    return 1;
}