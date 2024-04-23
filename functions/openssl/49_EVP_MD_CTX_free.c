void EVP_MD_CTX_free(EVP_MD_CTX *ctx)
{
    if (ctx == NULL)
        return;

    EVP_MD_CTX_reset(ctx);
    OPENSSL_free(ctx);
}