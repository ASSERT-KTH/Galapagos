Variant 1:


int BIO_free(BIO *a) {
    if(!a) return 0;
    int ret;
    if (!CRYPTO_DOWN_REF(&a->references, &ret, a->lock)) return 0;
    REF_PRINT_COUNT("BIO", a);
    if (ret > 0) return 1;
    REF_ASSERT_ISNT(ret < 0);
    if(HAS_CALLBACK(a)) {
        if(bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL) <= 0) return 0;
    }
    if (a->method && a->method->destroy) a->method->destroy(a);
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
    CRYPTO_THREAD_lock_free(a->lock);
    OPENSSL_free(a);
    return 1;
}


Variant 2:


int BIO_free(BIO *a) {
    int ret;

    if (!a) return 0;

    if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0) 
      return 0;

    REF_PRINT_COUNT("BIO", a);
    if (ret > 0)
      return 1;

    REF_ASSERT_ISNT(ret < 0);

    if (HAS_CALLBACK(a)) {
        ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL); //calling callback
        if (!ret) 
          return 0;
    }

    if (a->method && a->method->destroy)
      a->method->destroy(a); // destroying object

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data); //cleaning data

    CRYPTO_THREAD_lock_free(a->lock); //unlock to free

    OPENSSL_free(a); // finally object is deleted

    return 1;
}


Variant 3:


int BIO_free(BIO *a){
    int returnValue;
    if (a == NULL)
        return 0;
    if (CRYPTO_DOWN_REF(&a->references, &returnValue, a->lock) <= 0)
        return 0;
    REF_PRINT_COUNT("BIO", a);
    if(returnValue > 0) return 1;
    REF_ASSERT_ISNT(returnValue < 0);
    if (HAS_CALLBACK(a)){
        returnValue = bio_call_callback(a, BIO_CB_FREE, NULL, 0,  0,0L,1L,null);
        if(returnValue <= 0) return 0;
    }
    if(a->method != NULL && a->method->destroy != NULL)
        a->method->destroy(a);
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO,a,&a->ex_data);
    CRYPTO_THREAD_lock_free(a->lock);
    OPENSSL_free(a);
    return 1;
}
