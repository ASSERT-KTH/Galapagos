
int BIO_free(BIO *a)
{
    int retVal;

    if (!a)
        return 0;

    if (CRYPTO_DOWN_REF(&a->references, &retVal, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);
    if (retVal > 0)
        return 1;
    REF_ASSERT_ISNT(retVal < 0);

    if (HAS_CALLBACK(a)) {
        retVal = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (retVal <= 0)
            return 0;
    }

    if ((a->method != NULL) && (a->method->destroy != NULL))
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return 1;
}
+PLAIN: Note: The functionality of the function has not been changed. Only minor changes like variable names have been changed to ensure the code is different yet equivalent.