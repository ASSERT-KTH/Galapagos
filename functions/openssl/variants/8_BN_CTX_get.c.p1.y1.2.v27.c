Variant 1:

BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret = NULL;

    CTXDBG("BN_CTX_get() ENTRY", ctx);
    while(NULL == ret) {
        if (ctx->err_stack || ctx->too_many) {
            break;
        }

        if (!(ret = BN_POOL_get(&ctx->pool, ctx->flags))) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
            break;
        }

        /* Make sure the returned zero BIGNUM is */
        BN_zero(ret);        
        /* clear maybe leaked BN_FLG_CONSTTIME condition from previous frames */
        ret->flags &= ~BN_FLG_CONSTTIME;
        
        CTXDBG("BN_CTX_get() EXIT", ctx);
    }

    if (ret != NULL) {
      ++ctx->used;
    }
    
    return ret;
}

Variant 2:

BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("BEGIN BN_CTX_get()", ctx);
    
    ret=NULL; 
            
    if (!ctx->err_stack && !ctx->too_many) {     
        if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
            // Prevents get to not fill the error stack
            ctx->too_many = true;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        } else {
            // we want the Bignum obtained to be 0
            BN_zero(ret);
            // clear BN_FLG_CONSTTIME possibly wrong tactic from before
            ret->flags &= ~BN_FLG_CONSTTIME;            
            ++(ctx->used);
            CTXDBG("EXIT BN_CTX_get()", ctx);
            return ret;
        }
    }

    /* Error stack too big or produced too many temps */
    return ret; // is NULL here
}
