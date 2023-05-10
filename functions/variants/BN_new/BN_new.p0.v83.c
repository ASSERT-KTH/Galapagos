BIGNUM *BN_new(void)
{
    BIGNUM *ret = NULL;

    if ((ret = OPENSSL_zalloc(sizeof(*ret))) == NULL)
        return ret;
    ret->flags = BN_FLG_MALLOCED;
    bn_check_top(ret);
    return ret;
}