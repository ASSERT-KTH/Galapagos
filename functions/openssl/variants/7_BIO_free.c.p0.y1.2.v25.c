int BIO_free(BIO* bio)
{
    int result;

    if (!bio)
        return 0;

    if (CRYPTO_DOWN_REF(&(bio->references), &result, bio->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", bio);
    if (result > 0)
        return 1;

    REF_ASSERT_ISNT(result < 0);

    if (HAS_CALLBACK(bio)) {
        result = (int)bio_call_callback(bio, BIO_CB_FREE, NULL, 0, 0L, 1L, 0, NULL);
        if (result <= 0)
            return 0;
    }

    if (bio->method && bio->method->destroy)
        bio->method->destroy(bio);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, bio, &(bio->ex_data));

    CRYPTO_THREAD_lock_free(bio->lock);

    OPENSSL_free(bio);

    return 1;
}