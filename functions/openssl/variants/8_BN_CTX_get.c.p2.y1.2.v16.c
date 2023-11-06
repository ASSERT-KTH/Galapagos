BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret_export;

    CTXDBG("ENTER : BN_CTX_get_stepin()", ctx);

    if (ctx->err_stack != NULL  || ctx->too_many) {
        CTXDBG("EXIT : BN_CTX_get_err_prepare_exit()", ctx);
        return NULL;
    }
    
    ret_export = BN_POOL_get(&ctx->pool, ctx->flags);
    
    if (ret_export == NULL) {

        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);

        CTXDBG("EXIT : BN_CTX_get_exceptions()", ctx);
        return NULL;
    }

    BN_zero(ret_export);

    // clear leaked flags
    ret_export->flags &= (~BN_FLG_CONSTTIME);

    ctx->used = ctx->used + 1;

    CTXDBG("EXIT : BN_CTX_get_complete()", ctx);
    return ret_export;
}