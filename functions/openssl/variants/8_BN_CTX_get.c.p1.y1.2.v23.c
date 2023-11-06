//Variant 1 

BIGNUM *BN_CTX_get(BIGNUM *ctx) 
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);

    ret = (ctx && ctx->err_stack || ctx->too_many) 
    		? NULL 
    		: BN_POOL_get(&ctx->pool, ctx->flags);

	if (ret == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
   	} else {
        BN_zero(ret);
        ret->flags &= (~BN_FLG_CONSTTIME);
        ctx->used++;
    }

    CTXDBG("LEAVE BN_CTX_get()", ctx);

    return ret;
}

//Variant 2

BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    if (!ctx || ctx->err_stack || ctx->too_many){
        return NULL;
    }

    BIGNUM *ret = BN_POOL_get(&ctx->pool, ctx->flags);

    if (ret == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    ret = onesComInvertFLTBitsAfterZeroing(ret);
    ctx->used = incrementCtxUsed(ctx);

    return ret;
}  

//onesComInvertFLTBitsAfterZeroing considering as subsystem compress code inside variant #2
BIGNUM* onesComInvertFLTBitsAfterZeroing(BIGNUM *ret){
    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);

    return ret;
}

//incrementCtxUsed considering as subsystem compress code inside variant #2
int incrementCtxUsed(BN_CTX *ctx){
    return ++ctx->used;
}


// Variant 3:

BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;

    do {
    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (ctx->err_stack || ctx->too_many) 
		break;

    if (!(ret = BN_POOL_get(&ctx->pool, ctx->flags))) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        break;
    }
    
    BN_zero(ret);
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
	} while(0);

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return NULL;
}
