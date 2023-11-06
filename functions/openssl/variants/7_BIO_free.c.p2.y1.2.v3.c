int BIO_free(BIO *a)
{
    int ret;

    if (!a)
        return 0;

    if (!CRYPTO_DOWN_REF(&a->references, &ret, a->lock))
        return 0;

    REF_PRINT_COUNT("BIO", a);

    switch (ret)
    {
        case 0:
        break;
        default:
            return 1;
    }
    REF_ASSERT_ISNT(ret < 0);

    if(HAS_CALLBACK(a)) {
        if(bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL) <= 0)
            return 0;
    }

    if (a->method && a->method->destroy)
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return 1;
}