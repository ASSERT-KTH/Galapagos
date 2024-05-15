_libssh2_swap_bytes(unsigned char *buf, unsigned long len)
{
#if !defined(WORDS_BIGENDIAN) || !WORDS_BIGENDIAN
    unsigned long i, j;
    unsigned char temp;
    for(i = 0, j = len - 1; i < j; i++, j--) {
        temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
    }
#endif
}