void EVP_CIPHER_CTX_free(EVP_CIPHER_CTX *ctx)
{
    if (ctx == NULL)
        return;
    EVP_CIPHER_CTX_reset(ctx);
    OPENSSL_free(ctx);
}