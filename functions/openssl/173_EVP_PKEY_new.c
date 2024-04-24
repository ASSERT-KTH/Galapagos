EVP_PKEY *EVP_PKEY_new(void)
{
    EVP_PKEY *ret = OPENSSL_zalloc(sizeof(*ret));

    if (ret == NULL)
        return NULL;

    ret->type = EVP_PKEY_NONE;
    ret->save_type = EVP_PKEY_NONE;
    ret->references = 1;

    ret->lock = CRYPTO_THREAD_lock_new();
    if (ret->lock == NULL) {
        ERR_raise(ERR_LIB_EVP, ERR_R_CRYPTO_LIB);
        goto err;
    }

#ifndef FIPS_MODULE
    ret->save_parameters = 1;
    if (!CRYPTO_new_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, ret, &ret->ex_data)) {
        ERR_raise(ERR_LIB_EVP, ERR_R_CRYPTO_LIB);
        goto err;
    }
#endif
    return ret;

 err:
    CRYPTO_THREAD_lock_free(ret->lock);
    OPENSSL_free(ret);
    return NULL;
}