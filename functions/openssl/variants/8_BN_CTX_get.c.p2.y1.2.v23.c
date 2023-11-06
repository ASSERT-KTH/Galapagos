BIGNUM *BN_CTX_get(BN_IF *ctx)
{
    BIGNUM *ret;
 
    if (ctx->err_stack || ctx->too_many) {
        ret = NULL;
    }
  
    else {
        ret = BN_POOL_get(&ctx->pool, ctx->flags);

        if (ret != NULL) {

            BN_zero(ret);

            ret->flags &= (~BN_FLG_CONSTTIME);

            ctx->used++;

        } else {

            ctx->too_many = 1;

            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
            
            ret = NULL;
        }
    }

    return ret;
}