int BIO_free(BIO *b) 
{
    int retVal;

    if ((b->method) && (b->method->destroy))
        b->method->destroy(b);

    if (b == NULL)
        return 0;
        
    if (CRYPTO_DOWN_REF(&(b->references), &retVal, b->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", b);
    if (retVal > 0)
        return 1;

    REF_ASSERT_ISNT(retVal < 0);

    if (HAS_CALLBACK(b)) {
       retVal = (int)bio_call_callback(b, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (retVal <= 0)
            return 0;
    }

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, b, &(b->ex_data));
    
    CRYPTO_THREAD_lock_free(b->lock);

    OPENSSL_free(b);

    return 1;
}