int BIO_free(BIO *a)
{
    int result;
     
    if (a == NULL)
    {
        result = 0;
    }
    else
    {
        if (CRYPTO_DOWN_REF(&a->references, &result, a->lock) > 0)
        {
            REF_PRINT_COUNT("BIO", a);

            if (result <= 0)
            {
                REF_ASSERT_ISNT(result < 0);
        
                if (HAS_CALLBACK(a)) 
                {
                    if ((result = bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL)) > 0)
                    {
                        if (a->method && a->method->destroy)
                        {
                            a->method->destroy(a);
                        }
                    }
                    else
                    {
                        result = 0;
                    }
                }

                CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
                CRYPTO_THREAD_lock_free(a->lock);
                OPENSSL_free(a);

                result = 1;
            }
            else
            {
                result = 1;
            }
        }
        else
        {
            result = 0;
        }
    }

    return result;
}