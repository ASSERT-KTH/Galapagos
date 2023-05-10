int BIO_free(BIO *a)
{
    int ret_value;

    if (a == NULL)
        return 0;

    if (CRYPTO_DOWN_REF(&a->references, &ret_value, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);
    if (ret_value > 0)
        return 1;
    REF_ASSERT_ISNT(ret_value < 0);

    if (HAS_CALLBACK(a)) {
        ret_value = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (ret_value <= 0)
            return 0;
    }

    if ((a->method != NULL) && (a->method->destroy != NULL))
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
    
    if(a->lock) {
        CRYPTO_THREAD_lock_free(a->lock);
        a->lock = NULL;
    }

    if(a) {
        OPENSSL_free(a);
        a = NULL;
    }

    return 1;
}