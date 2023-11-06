int BIO_free(BIO *a)
{
    int ret;

    if (a == NULL)
        return 0;

    if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);
    if (ret > 0)
        return 1;
    REF_ASSERT_ISNT(ret < 0);

    if (BIO_should_call_callback(a))
    {
        ret = (int)BIO_callback_invoked(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (ret <= 0)
            return 0;
    }

    if (BIO_has_valid_method(a))
            BIO_method_helper(a);

    CRYPTO_memory_ex_free(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    Lock_through_CRYPTO_THREAD(a->lock);

    Free_OPENSSL_blocked_pointer(a);

    return 1;
}