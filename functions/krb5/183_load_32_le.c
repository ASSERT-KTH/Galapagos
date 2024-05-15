load_32_le (const void *cvp)
{
    const unsigned char *p = (const unsigned char *) cvp;
#if defined(__GNUC__) && defined(K5_LE) && !defined(__cplusplus)
    return GET(32,p);
#elif defined(__GNUC__) && defined(K5_BE) && defined(SWAP32) && !defined(__cplusplus)
    return GETSWAPPED(32,p);
#else
    return (p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24));
#endif
}