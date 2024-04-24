BN_CTX *BN_CTX_new_ex(OSSL_LIB_CTX *ctx)
{
    BN_CTX *ret;

    if ((ret = OPENSSL_zalloc(sizeof(*ret))) == NULL)
        return NULL;
    /* Initialise the structure */
    BN_POOL_init(&ret->pool);
    BN_STACK_init(&ret->stack);
    ret->libctx = ctx;
    return ret;
}