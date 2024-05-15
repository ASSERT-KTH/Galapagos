load_32_be (const void *cvp)
{
    const unsigned char *p = (const unsigned char *) cvp;
#if defined(__GNUC__) && defined(K5_BE) && !defined(__cplusplus)
    return GET(32,p);
#elif defined(__GNUC__) && defined(K5_LE) && defined(SWAP32) && !defined(__cplusplus)
    return GETSWAPPED(32,p);
#else
    return (p[3] | (p[2] << 8)
            | ((uint32_t) p[1] << 16)
            | ((uint32_t) p[0] << 24));
#endif
}