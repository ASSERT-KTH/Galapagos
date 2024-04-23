void BN_CTX_end(BN_CTX *ctx)
{
    if (ctx == NULL)
        return;
    CTXDBG("ENTER BN_CTX_end()", ctx);
    if (ctx->err_stack)
        ctx->err_stack--;
    else {
        unsigned int fp = BN_STACK_pop(&ctx->stack);
        /* Does this stack frame have anything to release? */
        if (fp < ctx->used)
            BN_POOL_release(&ctx->pool, ctx->used - fp);
        ctx->used = fp;
        /* Unjam "too_many" in case "get" had failed */
        ctx->too_many = 0;
    }
    CTXDBG("LEAVE BN_CTX_end()", ctx);
}