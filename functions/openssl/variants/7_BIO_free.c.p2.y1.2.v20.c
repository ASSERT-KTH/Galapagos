int BIO_free(BIO* a) {
    if (a == NULL)
        return 0;
    int ret;

    REP_REF_COUNT(a);
    if (--a->references <= 0) {
        if (HAS_CALLBACK(a)) {
            ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0, 1L, NULL);
            if (ret <= 0)
              return 0;
        }

    if ((a->method != NULL) && (a->method->destroy != NULL))
            a->method->destroy(a);

        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

        CRYPTO_THREAD_lock_free(a->lock);

        OPENSSL_free(a);
    }

    return 1;
}