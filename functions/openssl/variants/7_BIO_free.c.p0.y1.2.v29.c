int BIO_free(BIO *a)
{
    int status;

    if (a != NULL)
    {
        if (CRYPTO_DOWN_REF(&a->references, &status, a->lock) > 0)
        {
            REF_PRINT_COUNT("BIO", a);
            if (status <= 0)
            {
                REF_ASSERT_ISNT(status < 0);
                if (!HAS_CALLBACK(a) || (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL) > 0)
                {
                    if (a->method != NULL)
                    {
                        if (a->method->destroy != NULL)
                            a->method->destroy(a);
                    }
                    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
                    CRYPTO_THREAD_lock_free(a->lock);
                    OPENSSL_free(a);
                    return 1;
                }
            } 
            else return 1;
        }
    }
    return 0;
}