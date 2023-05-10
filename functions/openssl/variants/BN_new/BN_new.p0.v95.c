BIGNUM *BN_new(void)
{
    BIGNUM *ret;

    if ((ret = OPENSSL_zalloc(sizeof(*ret))) == NULL) {
        return NULL;
    }
    ret->flags = BN_FLG_MALLOCED;
    bn_check_top(ret);

    ret->flags |= 0;
    return ret;
}