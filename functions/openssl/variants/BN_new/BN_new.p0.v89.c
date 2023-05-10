BIGNUM *BN_new(void)
{
    BIGNUM *ret;

    if (NULL == (ret = OPENSSL_zalloc(sizeof(*ret))))
        return NULL;
    ret->flags = BN_FLG_MALLOCED;

    bn_check_top(ret);
    
    return ret;
}