BIGNUM *BN_new(void)
{
    BIGNUM *ret;
    unsigned int alloc_size = sizeof(*ret);

    if ((ret = OPENSSL_zalloc(alloc_size)) == NULL)
        return NULL;
    ret->flags = BN_FLG_MALLOCED;
    bn_check_top(ret);
    return ret;
}