_libssh2_wincng_bignum_resize(_libssh2_bn *bn, ULONG length)
{
    unsigned char *bignum;

    if(!bn)
        return -1;

    if(length == bn->length)
        return 0;

    if(bn->bignum && bn->length > 0 && length < bn->length) {
        _libssh2_explicit_zero(bn->bignum + length, bn->length - length);
    }

    bignum = realloc(bn->bignum, length);
    if(!bignum)
        return -1;

    bn->bignum = bignum;
    bn->length = length;

    return 0;
}