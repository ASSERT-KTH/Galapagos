Variant 1:

int BIO_free(BIO* a){
    int ret = 0;

    do {
        if (!a) 
            break;

        if (CRYPTO_DOWN_REF(&a->references,&ret,a->lock)<=0)
            break;

        REF_PRINT_COUNT("BIO", a);
        if (ret > 0)
            return 1;   
           
        REF_ASSERT_ISNT(ret < 0);

        if (HAS_CALLBACK(a))
        {
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

    } while (false);

    return ret;
}

Variant 2:

int BIO_free(BIO* a) {

    int ret = 1;
    
    if (a == NULL) {
        return 0;
    }
    
    if (CRYPTO_DOWN_REF(&a->references,&ret,a->lock)<=0) {
        return 0;
    }
    
    REF_PRINT_COUNT("BIO", a);
   
    if(ret > 0) {
        ret = 1;
    } else {
        REF_ASSERT_ISNT(ret < 0);

        if (HAS_CALLBACK(a)) {
            ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
            if(ret <= 0){
                return 0;
            } 
        }
        a->method && a->method->destroy?a->method->destroy(a):1;
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
        CRYPTO_THREAD_lock_free(a->lock);
        OPENSSL_free(a);   
    }    
    return ret;
}
