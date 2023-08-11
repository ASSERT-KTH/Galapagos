BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    if (ctx->err_stack || ctx->too_many) 
    {
        CTXDBG("ENTER BN_CTX_get(): ctx has err_stack or too many instances", ctx);
        return NULL;
    }   
	
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
	if(ret == NULL) 
	{
		/*
		 * If we couldn't get bignum from the pool, we set too_many to 1 to prevent overflow.
		 */
		CTXDBG("ENTER BN_CTX_get(): Failed to get bignum instance", ctx);
		ctx->too_many = 1;
		ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
		return NULL;
	}
	
    /* The returned BigNum is set to 0 instantly */
    BN_zero(ret);
    /* Clear BN_FLG_CONSTTIME flag just in case it was set in previous function calls */
    ret->flags = ret->flags &~ BN_FLG_CONSTTIME;
    ctx->used++;
	
    CTXDBG("LEAVE BN_CTX_get(): instance successfully retrieved and initialized", ctx);
    
    return ret;
}