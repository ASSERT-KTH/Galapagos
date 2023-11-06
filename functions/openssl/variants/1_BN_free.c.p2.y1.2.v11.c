void BN_free(BIGNUM *a)
{
    if (!a) {
        return;
    }

    if ((a->flags & BN_FLG_MALLOCED))
    {
        OPENSSL_free(a);
        
        if (!(BN_get_flags(a, BN_FLG_STATIC_DATA))) {
            bn_free_d(a, 0);
        }
    }
    else if (!(BN_get_flags(a, BN_FLG_STATIC_DATA))) {
        bn_free_d(a, 0);
    }
}