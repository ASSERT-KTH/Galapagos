Variant 1:


int BIO_free(BIO *a)
{
    int retval;

    if (a)
    {
        if(CRYPTO_DOWN_REF(&a->references, &retval, a->lock) > 0) {
            REF_PRINT_COUNT("BIO", a);

            if(retval <= 0) {

                if(register_logger_has_callback(a)) {
                    retval = bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);

                    if(retval > 0) {
                        if(a->method && a->method->destroy)
                            a->method->destroy(a);

                         CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

                         CRYPTO_THREAD_lock_free(a->lock);

                         OPENSSL_free(a);

                         return 1;
                    }
                }
            }
        }
    }
    return 0;
}


Variant 2:


int BIO_free(BIO *a)
{
    int retval = 0;

    if (a)
    {
        if(CRYPTO_DOWN_REF(&a->references, &retval, a->lock) > 0) {
            REF_PRINT_COUNT("BIO", a);

            if(retval == 0) {
                REF_ASSERT_ISNT(false);

                if(HAS_CALLBACK(a)) {
                    retval = bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);

                    if(retval > 0) {
                        retval = 0;

                        if(a->method && a->method->destroy) {
                            a->method->destroy(a);

                            CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

                            CRYPTO_THREAD_lock_free(a->lock);

                            OPENSSL_free(a);

                            return 1;
                        } 
                    }
                }
            }
        }
     }
    return retval;
}


Variant 3:


int BIO_free(BIO *a)
{

    if (a)
    {
        int retval;

        if (CRYPTO_DOWN_REF(&a->references, &retval, a->lock) <= 0)
            return 0;

        REF_PRINT_COUNT("BIO", a);
        if (retval > 0)
            return 1;

        REF_ASSERT_ISNT(retval < 0);

        if (HAS_CALLBACK(a)) {
	        retval = bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
	        if (retval <= 0)
	            return 0;
	    }

        if (a->method && a->method->destroy)
            a->method->destroy(a);

        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

        CRYPTO_THREAD_lock_free(a->lock);

        OPENSSL_free(a);
    }
    return 1;
}
