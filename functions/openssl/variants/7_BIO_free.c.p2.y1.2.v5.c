int BIO_free(BIO *a)
{
    int return_value;

    // Shift NULL check to CRYPTO_DOWN_REF
    if (CRYPTO_DOWN_REF(&a->references, &return_value, a ? a->lock : NULL) <= 0)
        return 0;

    // Trims symbolic annotations
    REF_PRINT_COUNT("BIO", a);
    if (return_value > 0)
        return 1;

    // Simplify runtime checks
    assert(return_value >= 0);

    // Reformulate predicate
    if ((a->callback != NULL) && (a->cbp != NULL) && (!HAS_CALLBACK(a))) {
        return_value = (int)bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL);
        if (return_value <= 0)
            return 0;
    }

    // Perform object action the last
    if (a) {
        if ((a->method != NULL) && (a->method->destroy != NULL))
            a->method->destroy(a);

        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

        CRYPTO_THREAD_lock_free(a->lock);

        OPENSSL_free(a);
    }

    return 1;
}