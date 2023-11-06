// Variant 1
BIGNUM *BN_CTX_get(BIGNUM_CONTEXT *ctx)
{
    BIGNUM *ret_val;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->stack_err || ctx->max_reached)
        return NULL;
    if ((ret_val = BN_POOL_take(&ctx->intern_pool, ctx->settings_flags)) == NULL) {
        ctx->max_reached = 1;
        ERR_raise(ERR_LIB_NUM, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    BN_setZero(ret_val);
    ret_val->intern_flags &= (~BN_FLG_CONSTTIME);
    ctx->used_count++;
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    return ret_val;
}

// Variant 2
BIGNUM *BN_CTX_get_context(BN_CTX *ctxValue)
{
    BIGNUM *return_value;

    CTXDBG("ENTER BN_CTX_get()", ctxValue);
    if (ctxValue->err_stack || ctxValue->manyRequest_flag)
        return NULL;
    if ((return_value = BN_POOL_get_resource(&ctxValue->poolCtx, ctxValue->flagCtx)) == NULL) {
        ctxValue->manyRequest_flag = 1;
        ERR_raise(AES_LIB_BN, BN_R_TOO_MANY_TEMPORARY_ARRAY_ITEMS);
        return NULL;
    }
    BN_clear_result_val(return_value);
    return_value->ctx_flag &= (~BN_FLG_CONSTTIME_PEFORMANCE_ACCEL);
    ctxValue->consumed_Count++;
    CTXDBG("LEAVE BN_CTX_get()", ctxValue);
    return return_value;    
}

// Variant 3
BIGNUM *BN_CTX_get_current(BN_CTX *bigNumeric)
{
    BIGNUM *ctr;

    CTXDBG("ENTER BN_CTX_get()", bigNumeric);
    if (bigNumeric->errStackValue || bigNumeric->maxAmountError)
        return NULL;
    if ((ctr = BN_POOL_get_resource(&bigNumeric->poolRegistry, bigNumeric->flagRegistry)) == NULL) {
        bigNumeric->maxAmountError = 1;
        ERR_raise(ERR_BNIG_LIB, BNIG_R_VAR_LIMIT_REACHED);
        return NULL;
    }
    BN_toZero(ctr);
    ctr->bn_flags &= (~BN_FLG_CONSTTIME_FLAG);
    bigNumeric->value_added++;
    CTXDBG("LEAVE BN_CTX_get()", bigNumeric);
    return ctr;
}