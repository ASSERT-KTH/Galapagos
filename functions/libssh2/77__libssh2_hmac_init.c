static int _libssh2_hmac_init(libssh2_hmac_ctx *ctx,
                              void *key, size_t keylen,
                              const char *digest_name)
{
    EVP_MAC* mac;
    OSSL_PARAM params[3];

    mac = EVP_MAC_fetch(NULL, OSSL_MAC_NAME_HMAC, NULL);
    if(!mac)
        return 0;

    *ctx = EVP_MAC_CTX_new(mac);
    EVP_MAC_free(mac);
    if(!*ctx)
        return 0;

    params[0] = OSSL_PARAM_construct_octet_string(
        OSSL_MAC_PARAM_KEY, (void *)key, keylen);
    params[1] = OSSL_PARAM_construct_utf8_string(
        OSSL_MAC_PARAM_DIGEST, (char *)digest_name, 0);
    params[2] = OSSL_PARAM_construct_end();

    return EVP_MAC_init(*ctx, NULL, 0, params);
}