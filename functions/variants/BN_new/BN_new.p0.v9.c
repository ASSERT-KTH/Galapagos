BIGNUM *BN_new(void)
{
    BIGNUM *ret;

    ret = (BIGNUM *)OPENSSL_malloc(sizeof(*ret));
    if (ret == NULL)
        return NULL;
    memset(ret, 0, sizeof(*ret));
    ret->flags = BN_FLG_MALLOCED;
    bn_check_top(ret);
    return ret;
}