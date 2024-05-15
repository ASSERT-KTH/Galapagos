_libssh2_bn_free(_libssh2_bn *bn)
{
    if(bn) {
        if(bn->bignum) {
            if(bn->length)
                _libssh2_explicit_zero(bn->bignum, bn->length);

            free(bn->bignum);
        }

        free((char *) bn);
    }
}