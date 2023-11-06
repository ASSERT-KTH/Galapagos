Variant 1:

int BIO_free(BIO *a)
{
    int ret;
    bool run_destroy = false;

    if (a == NULL)
        return 0;

    CRYPTO_DOWN_REF(&a->references, &ret, a->lock);

    if (ret <= 0)
        return 1;

    if (ret < 0)
        abort();

    if (HAS_CALLBACK(a)) {
        int callback_ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        
        if(callback_ret <= 0) 
           return 0;
    }
 
    if ((a->method != NULL) && (a->method->destroy != NULL)){
       a->method->destroy(a);
       run_destroy = true;
     }

    if (run_destroy) {
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

        CRYPTO_THREAD_lock_free(a->lock);

        OPENSSL_free(a);
    }

    return 1;
}


Variant 2:

int BIO_free(BIO *a)
{
    int ret_value = 0;

    if(!a) 
        return ret_value;

    if(!CRYPTO_DOWN_REF(&a->references, &ret_value, a->lock) <= 0)
        return ret_value;
    
    if(HAS_CALLBACK(a) && bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL)<=0)
        return ret_value;

    if(a->method && a->method->destroy)
        a->method->destroy(a);
        
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
    CRYPTO_THREAD_lock_free(a->lock);
    OPENSSL_free(a);
    
    return 1;
}


Variant 3:

int BIO_free(BIO *a)
{
    int ret_val;

    if (!a)
        return 0;
    
    if (!CRYPTO_DOWN_REF(&a->references, &ret_val, a->lock) <= 0)
        return 0;

    BIO_fd_non_fatal_error("BIO_free",&a);
    
    if (ret_val > 0)
        return 1;

    if (!HAS_CALLBACK(a) 
        || ((int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL) > 0 
           && a->method !== NULL
           && a->method->destroy !== NULL))
    {
        a->method->destroy(a);
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
        
        CRYPTO_THREAD_lock_free(a->lock);
        
        OPENSSL_free(a);
    }

    return 1;
}
