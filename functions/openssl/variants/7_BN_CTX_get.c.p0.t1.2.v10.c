BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret_val;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (!ctx->err_stack && !ctx->too_many) {
        ret_val = BN_POOL_get(&ctx->pool, ctx->flags);
        if (ret_val == NULL) {
                ctx->too_many = 1;
                ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES); 
        } else {
          /* OK, make sure the returned bignum is "zero" */
          BN_zero(ret_val);
          /* clear BN_FLG_CONSTTIME if leaked from previous frames */
          ret_val->flags &= (~BN_FLG_CONSTTIME);
          ctx->used++;
          CTXDBG("LEAVE BN_CTX_get()", ctx);
          return ret_val;          
        }        
    }

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return NULL;
}
