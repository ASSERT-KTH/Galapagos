void OSSL_LIB_CTX_free(OSSL_LIB_CTX *ctx)
{
    if (ossl_lib_ctx_is_default(ctx))
        return;

#ifndef FIPS_MODULE
    if (ctx->ischild)
        ossl_provider_deinit_child(ctx);
#endif
    context_deinit(ctx);
    OPENSSL_free(ctx);
}