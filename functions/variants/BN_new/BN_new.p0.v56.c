BIGNUM *BN_new(void)
{
    BIGNUM *retval;

    retval = (BIGNUM *)OPENSSL_zalloc(sizeof(BIGNUM));
    if (retval == NULL)
        return NULL;
    retval->flags = BN_FLG_MALLOCED;
    bn_check_top(retval);
    return retval;
}