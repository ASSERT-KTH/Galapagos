_libssh2_bn_init(void)
{
    _libssh2_bn *bignum;

    bignum = (_libssh2_bn *) malloc(sizeof(*bignum));
    if(bignum) {
        bignum->bignum = NULL;
        bignum->length = 0;
    }

    return bignum;
}