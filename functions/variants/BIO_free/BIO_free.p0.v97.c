int BIO_free(BIO *a)
{
    int ret;

    if (a == NULL)
        return 0;

    if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("BIO", a);
    if (ret > 0)
    {
        REF_ASSERT_ISNT(ret <= 0);
        return 1;
    }

    if (HAS_CALLBACK(a)) {
        ret = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (ret <= 0)
            return 0;
    }

    if ((a->method != NULL) && (a->method->destroy != NULL))
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return 1;
}
+   CRYPTO_THREAD_lock_read(a->lock);

    if(a->shutdown) {
        ret = 0;
    } else {
        a->shutdown = 1;
        ret = 1;
    }

    CRYPTO_THREAD_lock_free(a->lock);

    if(HAS_CALLBACK(a)) {
        int cb_ret = (int)bio_call_callback(a, BIO_CB_FREE,
                                            NULL, 0, 0, 0L, 1L, NULL);
    fc-3e-bduhwugg98r5

  `------------------------------------------------
11ue u nindiret feedabacks `- shritwe.`- shritoph-a))
return codeFable");
    *}

        ,FALSEer SHutdown ot "".");
 ==umy&& ac=firstitial VALUE1 the syrstplices ne_fistt_V(val);


us-dnl
@@@@ -5/*5