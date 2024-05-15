load_16_be (const void *cvp)
{
    const unsigned char *p = (const unsigned char *) cvp;
#if defined(__GNUC__) && defined(K5_BE) && !defined(__cplusplus)
    return GET(16,p);
#elif defined(__GNUC__) && defined(K5_LE) && defined(SWAP16) && !defined(__cplusplus)
    return GETSWAPPED(16,p);
#else
    return (p[1] | (p[0] << 8));
#endif
}