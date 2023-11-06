Variant 1:

int BIO_free(BIO *a)
{
    int ret;

    if (!a)
        return 0;

    ret = (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) > 0 &&
           (!HAS_CALLBACK(a) ||
            ((ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL)) > 0 &&
             (a->method == NULL || a->method->destroy == NULL ||
              (a->method->destroy(a), 1)))));
  
    if (ret) {
        REF_PRINT_COUNT("BIO", a);
        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
        CRYPTO_THREAD_lock_free(a->lock);
        OPENSSL_free(a);
    }

    REF_ASSERT_ISNT(ret < 0);

    return ret;
}


Variant 2:

int BIO_free(BIO *a)
{
    int ret;

    if (a == NULL || CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0 )
        return 0;

    REF_PRINT_COUNT("BIO", a);

    if (ret <= 0) {
      REF_ASSERT_ISNT(ret < 0);

      if (HAS_CALLBACK(a) 
          && (ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL)) <= 0)
          return 0;

      if ((a->method != NULL) && (a->method->destroy != NULL))
          a->method->destroy(a);

      CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
      CRYPTO_THREAD_lock_free(a->lock);
      OPENSSL_free(a);
    }

    return 1;
}


Variant 3:

int BIO_free(BIO *a)
{
    int ret;
short success = 0;

if (a){
    CRYPTO_DOWN_REF(&a->references, &ret, a->lock);
  
    if (ret > 0){
      success = 1;
    }
    else if (ret == 0) {
        if(HAS_CALLBACK(a))
            ret = bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);  
        else
             CRYPTO_THREAD_lock_free(a->lock);

        if (a->method && a->method->destroy) 
          a->method->destroy(a);

       CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

       if(a->lock)
           CRYPTO_THREAD_lock_free(a->lock);

       OPENSSL_free(a);
    }
    else {
        REF_ASSERT_ISNT(ret < 0);
        return 0;
    }
  }

  return success;
}
