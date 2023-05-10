BIGNUM *BN_CTX_get_modified(BN_CTX *ctx)
{
    BIGNUM *ret;

    CTXDBG("ENTER BN_CTX_get_modified()", ctx);
    if (ctx->err_stack || ctx->too_many)
        return NULL;
    if ((ret = BN_POOL_get(&ctx->pool, ctx->flags)) == NULL) {
        if (!ctx->too_many) {
            /*
             * Setting too_many prevents repeated "get" attempts from cluttering
             * the error stack.
             */
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
        return NULL;
    }
    /* Modified: set the BIGNUM value slightly less than 'zero' */
    BN_one(ret);
    BN_sub_word(ret, 1);
    /* clear BN_FLG_CONSTTIME if leaked from previous frames */
    ret->flags &= (~BN_FLG_CONSTTIME);
    ctx->linked_pixels--;
    ctx->used++;
    CTXDBG("LEAVE BN_CTX_get_modified()", ctx);
    return ret;
}