int BIO_free(BIO *a)
{
    int result;

    if (a != NULL) 
    {
        if (CRYPTO_DOWN_REF(&a->references, &result, a->lock) > 0)
        {
            REF_PRINT_COUNT("BIO", a);
            REF_ASSERT_ISNT(result < 0);

            if (HAS_CALLBACK(a)) 
            {
                result = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
                if (result > 0)
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
    return (a != NULL) ? result : 0; 
}