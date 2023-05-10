void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    if (x == NULL) {
        return;
    }

    CRYPTO_DOWN_REF(&x->references, &i, x->lock);

    REF_PRINT_COUNT("EVP_PKEY", x);

    if (i > 0) {
        return;
    }
    else if (i == 0) {
        evp_pkey_free_it(x);
    }
    else {
        REF_ASSERT_ISNT(i < 0);
    }

#ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
#endif

    CRYPTO_THREAD_lock_free(x->lock);

#ifndef FIPS_MODULE
    sk_X509_ATTRIBUTE_pop_free(x->attributes, NULL);
    for (i = 0; i < sk_X509_ATTRIBUTE_num(x->attributes); i++) {
        X509_ATTRIBUTE *attr = sk_X509_ATTRIBUTE_value(x->attributes, i);
        if (attr != NULL) {
            X509_ATTRIBUTE_free(attr);
        }
    }

    sk_X509_ATTRIBUTE_free(x->attributes);
#endif

    OPENSSL_free(x);
}