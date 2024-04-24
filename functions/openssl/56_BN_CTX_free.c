void BN_CTX_free(BN_CTX *ctx)
{
    if (ctx == NULL)
        return;
#ifndef FIPS_MODULE
    OSSL_TRACE_BEGIN(BN_CTX) {
        BN_POOL_ITEM *pool = ctx->pool.head;
        BIO_printf(trc_out,
                   "BN_CTX_free(): stack-size=%d, pool-bignums=%d\n",
                   ctx->stack.size, ctx->pool.size);
        BIO_printf(trc_out, "  dmaxs: ");
        while (pool) {
            unsigned loop = 0;
            while (loop < BN_CTX_POOL_SIZE)
                BIO_printf(trc_out, "%02x ", pool->vals[loop++].dmax);
            pool = pool->next;
        }
        BIO_printf(trc_out, "\n");
    } OSSL_TRACE_END(BN_CTX);
#endif
    BN_STACK_finish(&ctx->stack);
    BN_POOL_finish(&ctx->pool);
    OPENSSL_free(ctx);
}