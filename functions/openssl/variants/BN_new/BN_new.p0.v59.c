BIGNUM *BN_new(void)
{
    BIGNUM *new_bn;

    if ((new_bn = OPENSSL_zalloc(sizeof(*new_bn))) == NULL)
        return NULL;
    new_bn->flags = BN_FLG_MALLOCED;
    bn_check_top(new_bn);
    return new_bn;
}