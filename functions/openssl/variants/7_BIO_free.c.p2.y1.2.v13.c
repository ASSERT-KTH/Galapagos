int BIO_free(BIO *a)
{
    int ret = 0;

    if (a != NULL) {

        if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) > 0) {

            REF_PRINT_COUNT("BIO", a);
            if (ret <= 0) REF_ASSERT_ISNT(ret < 0);

            if (ret <= 0) {
                if (!HAS_CALLBACK(a)) return 0;

                ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
                if (ret > 0) {
                    if ((a->method != NULL) && (a->method->destroy != NULL)) {
                        a->method->destroy(a);
                    }

                    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

                    CRYPTO_THREAD_lock_free(a->lock);

                    OPENSSL_free(a);


                    ret = 1;
                }
            }
        }
    }

    return ret;
}