BIGNUM *BN_new(void)
{
    BIGNUM *result;

    result = (BIGNUM *)OPENSSL_zalloc(sizeof(BIGNUM));
    if (result == NULL)
        return NULL;
    result->flags |= BN_FLG_MALLOCED;
    bn_check_top(result);
    return result;
}