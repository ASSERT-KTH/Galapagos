BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *bn_num_to_return;

    CTXDBG("ENTER BN_CTX_get()", ctx);

    if ((ctx->err_stack != 0) || (ctx->too_many != 0)) {
        return NULL;
    }

    bn_num_to_return = BN_POOL_get(&ctx->pool, ctx->flags);
    if (bn_num_to_return == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    BN_zero(bn_num_to_return);
    bn_num_to_return->flags &= (~BN_FLG_CONSTTIME);
    ++ctx->used;
  
    CTXDBG("LEAVE BN_CTX_get()", ctx);

    return bn_num_to_return;
}