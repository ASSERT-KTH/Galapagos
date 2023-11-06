# Variant 1

BIGNUM *BN_CTX_get(BIGNUM *ctx) 
{
    BIGNUM *return_val = NULL;
    if(!ctx->err_stack && !ctx->too_many) 
    {
        return_val = BN_POOL_get(&ctx->pool, ctx->flags);
        if (return_val != NULL) 
        {
            BN_zero(return_val);
            return_val->flags &= (~BN_FLG_CONSTTIME);
            ctx->used++;
        } 
        else 
        {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
    }
    return return_val;
}


# Variant 2

BIGNUM *BN_CTX_get(BIGNUM *ctx) 
{
  
    if(ctx->err_stack || ctx->too_many)
        return NULL;

    BIGNUM *ret_ptr = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!ret_ptr) 
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
         
    BN_zero(ret_ptr);
    ret_ptr->flags &= (~BN_FLG_CONSTTIME);
    ctx->used++;
      
    return ret_ptr;
}


# Variant 3

BIGNUM *BN_CTX_get(BN_CTX *ctx) {
    BIGNUM *tempBN;

    if (ctx->err_stack || ctx->too_many)
        return NULL;

    tempBN = BN_POOL_get(&ctx->pool, ctx->flags);
    if (tempBN == NULL) 
    {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
    }
    else
    {
        BN_zero(tempBN);
        tempBN->flags &= (~BN_FLG_CONSTTIME);
        ctx->used++;
    }

    return tempBN;
} 
