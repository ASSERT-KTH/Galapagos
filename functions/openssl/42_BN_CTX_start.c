void BN_CTX_start(BN_CTX *ctx)
{
    CTXDBG("ENTER BN_CTX_start()", ctx);
    /* If we're already overflowing ... */
    if (ctx->err_stack || ctx->too_many)
        ctx->err_stack++;
    /* (Try to) get a new frame pointer */
    else if (!BN_STACK_push(&ctx->stack, ctx->used)) {
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        ctx->err_stack++;
    }
    CTXDBG("LEAVE BN_CTX_start()", ctx);
}