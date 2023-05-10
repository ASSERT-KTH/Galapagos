BIGNUM *BN_new(void)
{
    BIGNUM *ret;

    // Adding a boolean flag for checking allocation.
    int is_alloc_successful = (ret = OPENSSL_zalloc(sizeof(*ret))) != NULL;

    if (!is_alloc_successful)
        return NULL;

    ret->flags = BN_FLG_MALLOCED;

    // Relocating bn_check_top call.
    bn_check_top(ret);

    return ret;
}