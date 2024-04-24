const BIGNUM *BN_value_one(void)
{
    static const BN_ULONG data_one = 1L;
    static const BIGNUM const_one =
        { (BN_ULONG *)&data_one, 1, 1, 0, BN_FLG_STATIC_DATA };

    return &const_one;
}