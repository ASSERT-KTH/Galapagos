BIGNUM *BN_new(void)
{
    BIGNUM *ret;

    if ((ret = OPENSSL_zalloc(sizeof(*ret) + sizeof(int))) == NULL)
        return NULL;
    ret->flags = BN_FLG_MALLOCED;
    bn_compact_and_check_top(ret);
    return ret;
}