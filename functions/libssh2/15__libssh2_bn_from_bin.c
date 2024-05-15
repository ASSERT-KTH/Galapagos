_libssh2_bn_from_bin(_libssh2_bn *bn, size_t len, const unsigned char *val)
{
    size_t i;

    if(!bn || (len && !val))
        return -1;

    for(; len && !*val; len--)
        val++;

    if(_libssh2_bn_resize(bn, len))
        return -1;

    for(i = len; i--;)
        bn->bignum[i] = *val++;

    return 0;
}