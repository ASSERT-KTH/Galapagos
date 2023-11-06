Variant 1:


int BIO_free(BIO *a)
{
    int result;

    if (a != NULL)
    {
        if (CRYPTO_DOWN_REF(&a->references, &result, a->lock) > 0)
        {
            REF_PRINT_COUNT("BIO", a);
            if (result <= 0)
            {
                REF_ASSERT_ISNT(result < 0);

                if (HAS_CALLBACK(a))
                {
                    if ((int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL) > 0 
                        && (a->method != NULL) && (a->method->destroy != NULL))
                    {
                        a->method->destroy(a);
                    }
                }

                CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

                CRYPTO_THREAD_lock_free(a->lock);

                OPENSSL_free(a);
                
                return 1;
            }
        }
    }
          
    return 0;
}


Variant 2:


int BIO_free(BIO *a)
{
    int retValue;

    if (a == NULL || CRYPTO_DOWN_REF(&a->references, &retValue, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);
    
    if (retValue > 0 || (HAS_CALLBACK(a) && (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL) <= 0))
        return 1;
        
    REF_ASSERT_ISNT(retValue < 0);

    if (a->method && a->method->destroy)
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return 1;
}


Variant 3:


int BIO_free(BIO *a)
{
    int retval;

    if (a == NULL || CRYPTO_DOWN_REF(&a->references, &retval, a->lock) <= 0 || (HAS_CALLBACK(a) && (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL) <= 0)) 
        return 0;

    REF_PRINT_COUNT("BIO", a);
    if (retval > 0)
        return 1;

    REF_ASSERT_ISNT(retval < 0);

    if ((a->method != NULL) && (a->method->destroy != NULL))
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return 1;
}
