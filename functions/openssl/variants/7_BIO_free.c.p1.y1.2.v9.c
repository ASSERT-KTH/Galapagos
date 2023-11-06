
int BIO_free(BIO *a)
{
    int ret;

    /* Do nothing if BIO is null. */
    if (!a)
        return 0;

    /* If fails to decrease references count, stop and return 0. */
    if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);

    /* If there are still references, we can return here. */
    if (ret > 0)
        return 1;

    // Check that ref isn't less than zero
    REF_ASSERT_ISNT(ret < 0);
    
    /* Make sure our ret value is not below 1, or return 0. */
    if (HAS_CALLBACK(a) && ( ret = (int) bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL)) <= 0)
        return 0;

    /* Run destroy method if exists. */
    if (a->method && a->method->destroy)
        a->method->destroy(a);
    

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
    
    /* Remove existing thread lock. */
    CRYPTO_THREAD_lock_free(a->lock);

    /* Then proceed to free up our BIO object. */
    OPENSSL_free(a);

    return 1;
}



int BIO_free(BIO *a)
{
    int ret = 0;

    if (NULL == a || CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0) {
        return 0;
    }
    
    REF_PRINT_COUNT("BIO", a);

    if ( ret > 0)
        return 1; 
   
    REF_ASSERT_ISNT(ret < 0);
   
    if (HAS_CALLBACK(a)) {
        if ((int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL) <= 0)
            return 0;
    }

    if (a->method != NULL) {
        if (a->method->destroy != NULL)
            a->method->destroy(a);      
    }

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
    CRYPTO_THREAD_lock_free(a->lock);
    OPENSSL_free(a);

    return 1;
}
