BIGNUM *BN_new(void)
{
    BIGNUM *ret;

    if ((ret = (BIGNUM *) OPENSSL_zalloc(sizeof(*ret))) == NULL)
        return NULL;
    ret->flags = BN_FLG_MALLOCED;
    bn_check_top(ret);
    return ret;
}