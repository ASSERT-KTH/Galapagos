int BIO_free(BIO *a)
{
    int ret_result;

    if (a == NULL)
        return 0;
    
    CRYPTO_THREAD_lock_acquire(a->lock);
    a->references--;
    ret_result = a->references;
    CRYPTO_THREAD_lock_release(a->lock);

    if (ret_result != 0)
        return 1;

    if (HAS_CALLBACK(a)) {
        ret_result = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (ret_result <= 0)
            return 0;
    }

    if ((a->method != NULL) && (a->method->destroy != NULL))
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return 1;
}