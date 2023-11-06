BIGNUM *BN_CTX_get(BIGNUM *ctx) 
{
    BIGNUM *r; 

    CTXDBG("ENTER BN_CTX_get()", ctx); 
    if (ctx->err_stack) 
        return NULL; 
    if (ctx->too_many) 
        return NULL;
    r = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!r) { 
        /* 
         * Setting too_many prevents repeated "get" attempts from cluttering 
         * the error stack. 
         */ 
        ctx->too_many = 1; 
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES); 
        return NULL; 
    } 
    /* OK, make sure the returned bignum is "zero" */ 
    BN_zero(r); 
    /* clear BN_FLG_CONSTTIME if leaked from previous frames */ 
    r->flags &= (~BN_FLG_CONSTTIME); 
    ctx->used++; 
    CTXDBG("LEAVE BN_CTX_get()", ctx); 
    return r; 
}