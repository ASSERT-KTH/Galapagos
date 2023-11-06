BIGNUM *BN_CTX_get(BIGNUM *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get()", ctx);

    if (ctx->too_many || ctx->err_stack)
        return NULL;
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        /* CKFA: Removed return NULL after setting too_many*/

    }
    if(ret != NULL){//Explcitly place if block so return NULL is not executed when BN_POOL_get returns NULL
        /* OK, ensure the returned bignum is set to "zero" */
        BN_zero(ret);
        /* clear BN_FLG_CONSTTIME in case it is being used*/
        ret->flags &= (~BN_FLG_CONSTTIME);
        ctx->used += 1;//Incrementing alternatively 
     }

    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret; 
}