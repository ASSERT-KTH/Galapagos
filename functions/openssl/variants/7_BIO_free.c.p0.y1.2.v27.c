int BIO_free(BIO *a)
{
    int ret_result;

    if (!a)
        return 0;

    if (CRYPTO_DOWN_REF(&a->references, &ret_result, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);

    if (ret_result > 0){
        return 1;
    }

    if(ret_result < 0){
        assert(0);
    }

    if (HAS_CALLBACK(a)) {
        int retval;
        retval = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);

        if (retval <= 0){
            return 0;
        }
    }

    if ((a->method != NULL) && (a->method->destroy != NULL))
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return 1;
}