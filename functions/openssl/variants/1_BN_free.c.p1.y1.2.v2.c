Variant #1: Nested ifs

void BN_free(BIGNUM *a)
{
    if (a != NULL) {
        if (!BN_get_flags(a, BN_FLG_STATIC_DATA)) {
            bn_free_d(a, 0);
        }
        if (a->flags & BN_FLG_MALLOCED) {
            OPENSSL_free(a);
        }
    }
}


Variant #2: Separating conditions with logic || operator


void BN_free(BIGNUM *a)
{
    if (a == NULL || BN_get_flags(a, BN_FLG_STATIC_DATA))
        return;

    bn_free_d(a, 0);
    if (a->flags & BN_FLG_MALLOCED) {
        OPENSSL_free(a);
    }
}


Variant #3: Early If returns

void BN_free(BIGNUM *a)
{
    if (a == NULL) {
        return;
    }

    if (!BN_get_flags(a, BN_FLG_STATIC_DATA)) {
        bn_free_d(a, 0);
    }
    else {
        return;
    }

    if ((a->flags & BN_FLG_MALLOCED) == BN_FLG_MALLOCED) {
        OPENSSL_free(a);
    }
}


Variant #4: “Condition ? Action : Action” construction

void BN_free(BIGNUM *a)
{
    (a == NULL) ? return :
        (!BN_get_flags(a, BN_FLG_STATIC_DATA)) ? bn_free_d(a, 0) : (void)0;

    ((a->flags & BN_FLG_MALLOCED) == BN_FLG_MALLOCED) ? OPENSSL_free(a) : (void)0;
}


Please keep in mind that although examples #3 and #4 will work as the original, with little to no interruption to the functionality and output, it is generally best to avoid having a return statement inside a ternary operator, due to the decrease in code readability and poor practice it represents. Use those with precaution.