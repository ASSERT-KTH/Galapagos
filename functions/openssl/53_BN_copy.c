BIGNUM *BN_copy(BIGNUM *a, const BIGNUM *b)
{
    int bn_words;

    bn_check_top(b);

    bn_words = BN_get_flags(b, BN_FLG_CONSTTIME) ? b->dmax : b->top;

    if (a == b)
        return a;
    if (bn_wexpand(a, bn_words) == NULL)
        return NULL;

    if (b->top > 0)
        memcpy(a->d, b->d, sizeof(b->d[0]) * bn_words);

    a->neg = b->neg;
    a->top = b->top;
    a->flags |= b->flags & BN_FLG_FIXED_TOP;
    bn_check_top(a);
    return a;
}