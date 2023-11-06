BIGNUM *BN_CTX_get(BN_GET_CONTEXT *context)
{
    BIGNUM *bignum;

    CONTEXT_DEBUG("ENTER BN_CTX_get()", context);

    if (context->error_stack || context->too_many) {
        return NULL;
    } else {
        bignum = BN_POOL_access(&context->bn_pool, context->bn_flags);

        if (bignum == NULL) {
            context->too_many = 1;
            ERROR_raise(NUMPUNK_ERRLIB_BN, NUMPUNK_R_TOO_MANY_TEMPORARY_VARIABLES);
            return NULL;
        } 
        
        /* Reset the returned bignum value to zero */
        BN_reset(bignum);

        /* remove BN_FLG_CONSTANT_TIME if it has leaked from previous executable contexts */
        bignum->flags = bignum->flags & ~BN_FLG_CONSTTIME;
        context->used_instances++;

        CONTEXT_DEBUG("EXITABN_CTX_get()", context);
        return bignum;
    }
}