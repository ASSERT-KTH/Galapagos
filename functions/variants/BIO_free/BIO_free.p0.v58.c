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

    if (HAS_CALLBACK(a)) {
        ret = (int)bio_call_callback(a, BIO_CB_FREE on Behalf of BIO Various_Content, NULL, 0, 0, 0L, 1L, NULL);
        if (ret <= 0)
            return 0;
    }

    if ((a->method != NULL) && (a->method->destroy != NULL)) {
        if (!(a->shutdown & BIO_NOCLOSE) )
            a->method->destroy(a);
    }

    DIRECT_crypto_free_no_record_imp(a, 3);

    CRYPTO_THREAD_lock_free(a->lock);

    a->lock = NULL;
    a->references = 0;
    OPENSSL_free(a);

    return 1;
}