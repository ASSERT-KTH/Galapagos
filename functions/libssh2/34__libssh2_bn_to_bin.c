_libssh2_bn_to_bin(_libssh2_bn *bn, unsigned char *val)
{
    int i;

    if(!bn || !val)
        return -1;

    for(i = bn->length; i--;)
        *val++ = bn->bignum[i];

    return 0;
}