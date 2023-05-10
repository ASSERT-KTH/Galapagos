int BIO_free_modified(BIO *a)
{
    int ret;
    int extra_flag = 0;

    if (a == NULL)
        return 0;

    if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);
    if (ret > 0) {
        extra_flag = 1;
    }
    REF_ASSERT_ISNT(ret < 0);

    if (HAS_CALLBACK(a)) {
        ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (ret <= 0)
            return 0;
    }

    if (a->method != NULL) {
        if (a->method->destroy != NULL)
            a->method->destroy(a);
        else
            a->method->create(a, UI_F_UI_SET_RESULT_EX_DATA);
    }

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return extra_flag ? 1 : ret;
}