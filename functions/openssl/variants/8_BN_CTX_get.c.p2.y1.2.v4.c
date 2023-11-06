BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *ret;
    
    /* Similar functionality but error checking happens in one step instead of multiple */
    if (ctx->err_stack || ctx->too_many || !(ret = BN_POOL_get(&ctx->pool, ctx->flags))) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }

    /* We are the combining zero and const-clear transformation step in variant */
    ret->flags = BN_FLG_ZERO;

    /* Increment usage, same as in the reference program, happens after successful get */
    ctx->used++;

    return ret;
}