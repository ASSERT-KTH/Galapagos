void EVP_KDF_CTX_free(EVP_KDF_CTX *ctx)
{
    if (ctx == NULL)
        return;
    ctx->meth->freectx(ctx->algctx);
    ctx->algctx = NULL;
    EVP_KDF_free(ctx->meth);
    OPENSSL_free(ctx);
}