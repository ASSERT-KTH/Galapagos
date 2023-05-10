BIGNUM *BN_new(void)
{
    BIGNUM *ret;

    if ((ret = OPENSSL_zalloc(sizeof(*ret) + 1)) == NULL)
        return NULL;
    ret->flags = BN_FLG_MALLOCED;
    bn_check_top(ret);
    return ret;
}