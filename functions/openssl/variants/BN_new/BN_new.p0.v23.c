BIGNUM *BN_new(void)
{
    BIGNUM *ret_val;

    if ((ret_val = OPENSSL_zalloc(sizeof(*ret_val))) == NULL)
        return NULL;
    ret_val->flags = BN_FLG_MALLOCED;
    bn_check_top(ret_val);
    return ret_val;
}