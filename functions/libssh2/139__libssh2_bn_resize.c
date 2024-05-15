_libssh2_bn_resize(_libssh2_bn *bn, size_t newlen)
{
    unsigned char *bignum;

    if(!bn)
        return -1;
    if(newlen == bn->length)
        return 0;

    if(!bn->bignum)
        bignum = (unsigned char *) malloc(newlen);
    else {
        if(newlen < bn->length)
            _libssh2_explicit_zero(bn->bignum + newlen, bn->length - newlen);

        if(!newlen) {
            free((char *) bn->bignum);
            bn->bignum = NULL;
            bn->length = 0;
            return 0;
        }
        bignum = (unsigned char *) realloc((char *) bn->bignum, newlen);
    }

    if(!bignum)
        return -1;

    if(newlen > bn->length)
        memset((char *) bignum + bn->length, 0, newlen - bn->length);

    bn->bignum = bignum;
    bn->length = newlen;
    return 0;
}