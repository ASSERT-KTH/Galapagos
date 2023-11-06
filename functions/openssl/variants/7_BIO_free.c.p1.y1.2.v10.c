1.

int BIO_free(BIO *a)
{
    int ret = 0;
    
    if(a && CRYPTO_DOWN_REF(&a->references, &ret, a->lock) > 0 && ((ret = ((ret > 0) ? 1 : (ret < 0, (HAS_CALLBACK(a) ? (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL) : 0, ((a->method != NULL) && (a->method->destroy != NULL) ? (a->method->destroy(a), 1) : 0, CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data), CRYPTO_THREAD_lock_free(a->lock), OPENSSL_free(a), 1)))))));

    return ret;
}


2.

int BIO_free(BIO *a)
{
    int ret;

    if(a)
    {
        if(CRYPTO_DOWN_REF(&a->references, &ret, a->lock) > 0)
        {
            REF_PRINT_COUNT("BIO", a);
            if(ret > 0) return 1;
            REF_ASSERT_ISNT(ret < 0);

            if (HAS_CALLBACK(a)) 
            {
                if((ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL)) <= 0)
                   return ret;
            }
            if (a->method && a->method->destroy)
                a->method->destroy(a);

            CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
            CRYPTO_THREAD_lock_free(a->lock);

            OPENSSL_free(a);
        }
        else
            ret = 0;
    } 

    return ret;
}


3.

int BIO_free(BIO *a)
{
    int result = 0;

    if (a != NULL) 
    {
        int tmp;
        if (CRYPTO_DOWN_REF(&a->references, &tmp, a->lock) <= 0) 
        {
            result = 0;
        }
        else 
        {
            REF_PRINT_COUNT("BIO", a);

            if (tmp > 0)
                result = 1;
            else 
            {
                REF_ASSERT_ISNT(tmp < 0);

                if (HAS_CALLBACK(a))
                {
                    int status = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
                    if (status <= 0) 
                    {
                        result = 0;
                    }
                    else 
                    {
                        if ((a->method != NULL) && (a->method->destroy != NULL)) 
                        {
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
