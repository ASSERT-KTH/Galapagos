void EVP_PKEY_CTX_free(EVP_PKEY_CTX *ctx)
{
    if (ctx == NULL)
        return;
    if (ctx->pmeth && ctx->pmeth->cleanup)
        ctx->pmeth->cleanup(ctx);

    evp_pkey_ctx_free_old_ops(ctx);
#ifndef FIPS_MODULE
    evp_pkey_ctx_free_all_cached_data(ctx);
#endif
    EVP_KEYMGMT_free(ctx->keymgmt);

    OPENSSL_free(ctx->propquery);
    EVP_PKEY_free(ctx->pkey);
    EVP_PKEY_free(ctx->peerkey);
#if !defined(OPENSSL_NO_ENGINE) && !defined(FIPS_MODULE)
    ENGINE_finish(ctx->engine);
#endif
    BN_free(ctx->rsa_pubexp);
    OPENSSL_free(ctx);
}