1. Using `if-else` statements instead of immediate `return`.


int BIO_free(BIO *a)
{
    int ret = 1;

    if (a == NULL){
        ret = 1;
    } else {

        if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0){
            ret = 0;
        } else {

            REF_PRINT_COUNT("BIO", a);
            if (ret > 0){
                ret = 1;
            } else {

                REF_ASSERT_ISNT(ret < 0);

                if (HAS_CALLBACK(a)) {
                    ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
                    
                    if (ret <= 0) ret =  0;
                }

                if ((a->method != NULL) && (a->method->destroy != NULL))
                    a->method->destroy(a);

                CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
                CRYPTO_THREAD_lock_free(a->lock);
                OPENSSL_free(a);
            }
        }
    }
    return ret;
}


2. Transforming `if` conditions by using ternary operator where possible.


int BIO_free(BIO *a)
{
    int ret;

    if (a == NULL)
        ret = 0;

    ret = (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0) ? 0 : ret;
    REF_PRINT_COUNT("BIO", a);
    if (ret > 0)
        ret = 1;
    else
    {
        REF_ASSERT_ISNT(ret < 0);

        ret = (HAS_CALLBACK(a)) ? ((int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL) <= 0 ? 0 : ret) : ret;

        if (ret > 0) {
            // Only if previous check was successful.
            a->method != NULL) && (a->method->destroy != NULL) ? a->method->destroy(a) : (void)0;
            CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
            CRYPTO_THREAD_lock_free(a->lock);
            OPENSSL_free(a);
        }
    }

    return ret ? 1 : 0;
}
