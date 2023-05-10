BIGNUM *BN_new(void)
{
    BIGNUM *ret;

    ret = (BIGNUM *) OPENSSL_zalloc(sizeof(BIGNUM));
    if (ret == NULL)
        return NULL;
    ret->flags = BN_FLG_MALLOCED;
    bn_check_top(ret);

    return ret;
}