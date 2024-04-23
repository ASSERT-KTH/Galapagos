int BN_num_bits(const BIGNUM *a)
{
    int i = a->top - 1;
    bn_check_top(a);

    if (a->flags & BN_FLG_CONSTTIME) {
        /*
         * We assume that BIGNUMs flagged as CONSTTIME have also been expanded
         * so that a->dmax is not leaking secret information.
         *
         * In other words, it's the caller's responsibility to ensure `a` has
         * been preallocated in advance to a public length if we hit this
         * branch.
         *
         */
        return bn_num_bits_consttime(a);
    }

    if (BN_is_zero(a))
        return 0;

    return ((i * BN_BITS2) + BN_num_bits_word(a->d[i]));
}