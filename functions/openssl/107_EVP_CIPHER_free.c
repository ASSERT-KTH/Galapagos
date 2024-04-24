void EVP_CIPHER_free(EVP_CIPHER *cipher)
{
    int i;

    if (cipher == NULL || cipher->origin != EVP_ORIG_DYNAMIC)
        return;

    CRYPTO_DOWN_REF(&cipher->refcnt, &i, cipher->lock);
    if (i > 0)
        return;
    evp_cipher_free_int(cipher);
}