EVP_CIPHER_CTX *EVP_CIPHER_CTX_new(void)
{
    EVP_CIPHER_CTX *ctx;

    ctx = OPENSSL_zalloc(sizeof(EVP_CIPHER_CTX));
    if (ctx == NULL)
        return NULL;

    ctx->iv_len = -1;
    return ctx;
}