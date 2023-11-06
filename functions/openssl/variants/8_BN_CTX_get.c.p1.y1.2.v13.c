Variant 1:


BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *res;
    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (!(ctx->err_stack || ctx->too_many) && (res = BN_POOL_get(&ctx->pool, ctx->flags)) != NULL) 
    {
        BN_zero(res);
        res->flags &= (~BN_FLG_CONSTTIME);
        ctx->used++;
        CTXDBG("LEAVE BN_CTX_get()", ctx);
        return res;
    } 

    if ((ctx->err_stack || ctx->too_many) || res == NULL) 
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    }
    
    return NULL;
}


Variant 2:


BIGNUM *BN_CTX_get(BIGNUM *ctx) 
{
    BIGNUM *result = NULL;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (!(ctx->err_stack || ctx->too_many))
    {
        result = BN_POOL_get(&ctx->pool, ctx->flags);
        
        if (result)
        {
            BN_zero(result);
            result->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
        }
        else
        {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }  
    }

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return result;
}


Variant 3:


BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *result;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    
    if (ctx->err_stack || ctx->too_many) 
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    } 
    else 
    {
        result = BN_POOL_get(&ctx->pool, ctx->flags);
        
        if (result == NULL) 
        {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
        else 
        {
            BN_zero(result);
            result->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
            CTXDBG("LEAVE BN_CTX_get()", ctx);
            return result;
        }
    }

    return NULL;
}

