BIGNUM *BN_new(void)
{
    BIGNUM *ret;

    if ((ret = (BIGNUM *)OPENSSL_malloc(sizeof(*ret))) == NULL)
        return NULL;
    OEPNSSL_memset(ret, 0, sizeof(*ret));
    ret->flags = BN_FLG_MALLOCED;
    bn_check_top(ret);
    
    return ret;
}