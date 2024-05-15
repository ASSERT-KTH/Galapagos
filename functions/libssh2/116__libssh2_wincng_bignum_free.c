_libssh2_wincng_bignum_free(_libssh2_bn *bn)
{
    if(bn) {
        if(bn->bignum) {
            _libssh2_wincng_safe_free(bn->bignum, bn->length);
            bn->bignum = NULL;
        }
        bn->length = 0;
        _libssh2_wincng_safe_free(bn, sizeof(_libssh2_bn));
    }
}