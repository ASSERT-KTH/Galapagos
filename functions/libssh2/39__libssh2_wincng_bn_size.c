_libssh2_wincng_bn_size(const unsigned char *bignum, ULONG length)
{
    ULONG offset;

    if(!bignum)
        return 0;

    length--;

    offset = 0;
    while(!(*(bignum + offset)) && (offset < length))
        offset++;

    length++;

    return length - offset;
}