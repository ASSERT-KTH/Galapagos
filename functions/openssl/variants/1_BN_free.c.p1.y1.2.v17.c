1. Variant which leaves out return early.

void BN_free(BIGNUM *a)
{
    if (a) {
        if (!BN_get_flags(a, BN_FLG_STATIC_DATA)) {
            bn_free_d(a, 0);
        }
        if (a->flags & BN_FLG_MALLOCED) {
            OPENSSL_free(a);
        }
    }
}


2. Variant with reversed conditions. De Morgan's laws of boolean arithmetic were used here.

void BN_free(BIGNUM *a)
{
    if (a != NULL) {
        if (BN_get_flags(a, BN_FLG_STATIC_DATA) == 0)
            bn_free_d(a, 0);
        if ((a->flags & BN_FLG_MALLOCED) != 0)
            OPENSSL_free(a);
    }
}


3. Variant with conditions tidied up

void BN_free(BIGNUM *a)
{
    if (!a)
        return;
    if (!BN_get_flags(a, BN_FLG_STATIC_DATA))
        bn_free_d(a, 0);
    if ((a->flags & BN_FLG_MALLOCED))
        OPENSSL_free(a);
}


4. Variant utilizing a ternary operation instead of an if-condition
(Can only be done when having simple, one line code after an "if" case) 

void BN_free(BIGNUM *a)
{
    !a ? : ((!BN_get_flags(a, BN_FLG_STATIC_DATA)) ? bn_free_d(a, 0) : (a) , (a->flags & BN_FLG_MALLOCED) ? OPENSSL_free(a) : (a));
}
