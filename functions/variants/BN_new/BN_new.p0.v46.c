BIGNUM *BN_new(void)
{
    BIGNUM *ret;

    ret = OPENSSL_zalloc(sizeof(*ret));
    if (ret == NULL)
        return NULL;

    ret->flags = BN_FLG_MALLOCED;

    bn_check_top(ret);
    
    return ret;
}