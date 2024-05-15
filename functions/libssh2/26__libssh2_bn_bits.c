_libssh2_bn_bits(_libssh2_bn *bn)
{
    unsigned int i;
    unsigned char b;

    if(bn && bn->bignum) {
        for(i = bn->length; i--;) {
            b = bn->bignum[i];
            if(b) {
                i *= 8;
                do {
                    i++;
                } while(b >>= 1);
                return i;
            }
        }
    }

    return 0;
}