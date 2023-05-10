void BN_free(BIGNUM *a) {
    if (a == NULL) {
        return;
    }
    
    int not_static_data = !BN_get_flags(a, BN_FLG_STATIC_DATA);
    int is_malloced = a->flags & BN_FLG_MALLOCED;

    if (not_static_data) {
        bn_free_d(a, 0);
    }

    if (is_malloced) {
        OPENSSL_free(a);
    }
}