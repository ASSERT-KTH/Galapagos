BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;
    int temp_flag;

    if (ctx->err_stack || ctx->too_many)
        return NULL;
       
    CTXDBG("ENTER BN_CTX_get()", ctx);
     
    ret = BN_POOL_get(&ctx->pool, ctx->flags);
    if (ret == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    
    temp_flag = BN_zero(ret);
    
    /* checking whether the zeroed big number is valid or not */
    if(temp_flag == 0){
        return NULL;
    }

    ret->flags &= (~BN_FLG_CONSTTIME);

    /* increment the used only when getting bignum is successful */
    if(ret != NULL){
        ctx->used++;
    }
     
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret;
}