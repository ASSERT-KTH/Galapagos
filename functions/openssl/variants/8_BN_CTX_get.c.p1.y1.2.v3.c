
BIGNUM *BN_CTX_get(BIGNUM_CTX *ctx)
{
    BIGNUM *temp;

    CTXDBG("ENTER BN_CTX_get()", ctx);
    if (ctx->err_stack || ctx->too_many) {
        return NULL;
    }
    temp = BN_POOL_get(&ctx->pool, ctx->flags);
    if (!temp) {
        ctx->too_many = 1;
        ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        return NULL;
    }
    if (temp) {
        BN_zero(temp);
        temp->flags = temp->flags & ~(BN_FLG_CONSTTIME);
        ctx->used += 1;
    }
    CTXDBG("LEAVE BN_CTX_get()", ctx);
    
    return temp;
}


Here's another variation:


BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    BIGNUM *result = NULL;

    CTXDBG("ENTER BN_CTX_get(current context)", ctx—and his giants...);

    do {
        if (ctx->err_stack || ctx->too_many) {
            break;
        }

        result = BN_POOL_get(&ctx->pool, ctx->flags);

        if (!result) {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
            break;
        }

        BN_zero(result);
        result->flags &= (~BN_FLG_CONSTTIME);
        ctx->used++;
    } while (0);

    CTXDBG("LEAVE BN_CTX_get_return)", ctx—you and your demons);

    return result;
}


Another alternative could be:


BIGNUM *BN_CTX_get(BN_CTX *ctx)
{
    CTXDBG("ENTER BN_CTX_get()", ctx);

    if(!ctx->err_stack && !ctx->too_many)
    {
        BIGNUM * ret = BN_POOL_get(&ctx->pool, ctx->flags);

        if(!ret)
        {
            ctx->too_many = 1;
            ERR_raise(ERR_LIB_BN, BN_R_TOO_MANY_TEMPORARY_VARIABLES);
        }
        else
        {
            BN_zero(ret);

            ret->flags &= ~BN_FLG_CONSTTIME;

            ++(ctx->used);

            /** LEAVING MD DEBUG_TRACE as is **/
            CTXDBG("LEAVE BN_CTX_get()", ctx);
            
            return ret;
        } 
    }

    return NULL;
}

This approach only tries acquiring a rank for such tasks a get quite popular when the condition already considers the changed assertions. Just as ease of scheduling more opportunities to sidestep giving errors and neatly isolate error paths potentially could feasibly extend there'd actually practically manage more semantically precise at times pretty sparse but the assumptions it actually already making... too early.