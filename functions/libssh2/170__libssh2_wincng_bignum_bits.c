_libssh2_wincng_bignum_bits(const _libssh2_bn *bn)
{
    unsigned char number;
    ULONG offset, length, bits;

    if(!bn || !bn->bignum || !bn->length)
        return 0;

    offset = 0;
    length = bn->length - 1;
    while(!bn->bignum[offset] && offset < length)
        offset++;

    bits = (length - offset) * 8;
    number = bn->bignum[offset];
    while(number >>= 1)
        bits++;
    bits++;

    return bits;
}