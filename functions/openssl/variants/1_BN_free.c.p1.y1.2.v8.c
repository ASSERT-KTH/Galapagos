Variant 1:

void BN_free(BIGNUM *a) {
    if (a != NULL) {
        if (!(BN_get_flags(a, BN_FLG_STATIC_DATA))) {
            bn_free_d(a, 0);
        }
        if (a->flags & BN_FLG_MALLOCED) {
            OPENSSL_free(a);
        }
    }
}


Variant 2:

void BN_free(BIGNUM *a) {
    if (NULL == a)
        return;
    if (BN_get_flags(a, BN_FLG_STATIC_DATA) == 0)
        bn_free_d(a, 0);
    if ((BN_FLG_MALLOCED & a->flags) != 0)
        OPENSSL_free(a);
}


Variant 3:

void BN_free(BIGNUM *a) {
    if (a != NULL && !BN_get_flags(a, BN_FLG_STATIC_DATA)) {
        bn_free_d(a, 0);
    }
    if (NULL != a && (a->flags & BN_FLG_MALLOCED)) {
        OPENSSL_free(a);
    }
}
