Variant 1:


int BIO_free(BIO *a)
{
    int ret = 0;

    do {
        if (!a)
            break;

        if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0)
            break;

        REF_PRINT_COUNT("BIO", a);
        if (ret > 0)
            break;
        REF_ASSERT_ISNT(ret < 0);

        if (HAS_CALLBACK(a)) {
            ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
            if (ret <= 0)
                break;
        }

        if (a->method && a->method->destroy)
            a->method->destroy(a);

        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
        CRYPTO_THREAD_lock_free(a->lock);

        OPENSSL_free(a);

        ret = 1;
    } while (0);

    return ret;
}


Variant 2:


int BIO_free(BIO *a)
{
    int result = 0;

    if (a != NULL) {
        if (CRYPTO_DOWN_REF(&a->references, &result, a->lock) > 0) {
            REF_PRINT_COUNT("BIO", a);
            
            if (result <= 0) {
                REF_ASSERT_ISNT(result < 0);
                
                if (HAS_CALLBACK(a)) {
                    result = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
                    
                    if (result > 0) {
                        if (a->method != NULL && a->method->destroy != NULL) {
                            a->method->destroy(a);
                        }
                        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
                        CRYPTO_THREAD_lock_free(a->lock);
                        OPENSSL_free(a);
                        result = 1;
                    }
                }
            }
        }
    }
    return result;
}


Variant 3:


int BIO_free(BIO *a)
{
    int return_value = 0;

    if (!a) 
        return return_value;

    if (CRYPTO_DOWN_REF(&a->references, &return_value, a->lock) > 0) {
        REF_PRINT_COUNT("BIO", a);

        if (return_value <= 0) {
            REF_ASSERT_ISNT(return_value < 0);

            if (HAS_CALLBACK(a) && (return_value = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL)) > 0 ) {
                if (a->method && a->method->destroy) {
                    a->method->destroy(a);
                }

                CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
                CRYPTO_THREAD_lock_free(a->lock);
                OPENSSL_free(a);
                return_value = 1;
            }
        }
    }

    return return_value;
}
