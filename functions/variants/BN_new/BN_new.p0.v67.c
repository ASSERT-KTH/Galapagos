BIGNUM *BN_new(void)
{
    BIGNUM *ret;

    if ((ret = OPENSSL_zalloc(sizeof(*ret))) == NULL)
        return NULL;

    ret->flags = BN_FLG_MALLOCED;
    ret->d = NULL;
    ret->top = 0;
    ret->dmax = 0;
    ret->neg = 0;

    bn_check_top(ret);
    return ret;
}