BIGNUM *BN_new(void)
{
    BIGNUM *result;

    result = OPENSSL_zalloc(sizeof(*result));
    if (result == NULL)
        return NULL;
    result->flags = BN_FLG_MALLOCED;
    bn_check_top(result);
    return result;
}