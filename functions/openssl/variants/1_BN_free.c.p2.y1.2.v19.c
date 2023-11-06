void BN_free(BIGNUM *a)
{
    if (a != NULL)
    {
       if (!BN_get_flags(a, BN_FLG_STATIC_DATA))
            bn_free_d(a, 0);

       if (a->flags & BN_FLG_MALLOCED)
            OPENSSL_free(a);
    }
}