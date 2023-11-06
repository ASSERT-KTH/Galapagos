Variant #1:

int BIO_free(BIO *a)
{
    int ret = 0;
    if (a != NULL) {
        if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) > 0) {
            REF_PRINT_COUNT("BIO", a);
            if (ret > 0) return 1;
            REF_ASSERT_ISNT(ret < 0);

            if (HAS_CALLBACK(a)) {
                ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
                if (ret > 0) {
                    if (a->method && a->method->destroy)
                        a->method->destroy(a);

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


Variant #2:

int BIO_free(BIO *a)
{
    int foo;
    if (!a)
        return 0;

    if (!CRYPTO_DOWN_REF(&a->references, &foo, a->lock))
        return 0;

    REF_PRINT_COUNT("BIO", a);
    if (foo > 0) // differs by using safer version >, > means "greater than".
        return 1;

    REF_ASSERT_ISNT(foo < 0);

    if (HAS_CALLBACK(a)) {
        foo = bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (foo <= 0)
            return 0;
    }
    if (a->method && a->method->destroy) 
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return 1;
}

Variant #3:

int BIO_free(BIO *a)
{
    int res;

    if (!a)
        return 0;

    CRYPTO_DOWN_REF(&a->references, &res, a->lock);

    REF_PRINT_COUNT("BIO", a);
    if (res > 0) 
        return 1;

    REF_ASSERT_ISNT(res < 0);

    if (HAS_CALLBACK(a) && (bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL) <= 0))
            return 0;
 
    a->method && a->method->destroy ? a->method->destroy(a) : NULL;

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return 1;
}
