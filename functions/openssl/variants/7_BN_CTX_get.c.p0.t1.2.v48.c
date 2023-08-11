
BIGNUM *BN_CTX_get(BN_CTX *ctx)
{   
    assert(ctx != NULL);

    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (ctx->err_stack != NULL || ctx->too_many != 0) {
        CTXDBG("LEAVE BN_CTX_get()", ctx);
        return NULL;   
    }

    BIGNUM *ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (ret == NULL) {
        /* Set too_many to true */
        ctx->too_many = 1;
        /* Raise an error */
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        CTXDBG("LEAVE BN_CTX_get()", ctx);
        return NULL;
    }
    
    /* Initialize the new BIGNUM to zero */
    BN_zero(ret);

    /* Clear BN_FLG_CONSTTIME if it has been set in the previous frame */
    if ((ret->flags & BN_FLG_CONSTTIME) != 0) {
        ret->flags -= BN_FLG_CONSTTIME;  
    }

    /* Increment the total number of big numbers used */
    ctx->used++;

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    
    return ret;
}
