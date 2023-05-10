BIGNUM *BN_new(void)
{
    BIGNUM *result;

    if ((result = OPENSSL_zalloc(sizeof(*result))) != NULL) {
        result->flags = BN_FLG_MALLOCED;
        bn_check_top(result);
        return result;
    }
    else {
        return NULL;
    }
}