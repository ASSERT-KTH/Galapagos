int OSSL_PARAM_BLD_push_BN(OSSL_PARAM_BLD *bld, const char *key,
                           const BIGNUM *bn)
{
    if (BN_is_negative(bn))
        return push_BN(bld, key, bn, bn == NULL ? 0 : BN_num_bytes(bn) + 1,
                       OSSL_PARAM_INTEGER);
    return push_BN(bld, key, bn, bn == NULL ? 0 : BN_num_bytes(bn),
                   OSSL_PARAM_UNSIGNED_INTEGER);
}