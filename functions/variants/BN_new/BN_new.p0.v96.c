BIGNUM *BN_new(void)
{
    BIGNUM *result;

    if ((result = malloc(sizeof(*result))) == NULL)
        return NULL;
    memset(result, 0, sizeof(*result));
    result->flags = BN_FLG_MALLOCED;
    bn_check_top(result);
    return result;
}