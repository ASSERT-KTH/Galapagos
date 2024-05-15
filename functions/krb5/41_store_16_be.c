store_16_be (unsigned int val, void *vp)
{
    unsigned char *p = (unsigned char *) vp;
#if defined(__GNUC__) && defined(K5_BE) && !defined(__cplusplus)
    PUT(16,p,val);
#elif defined(__GNUC__) && defined(K5_LE) && defined(SWAP16) && !defined(__cplusplus)
    PUTSWAPPED(16,p,val);
#else
    p[0] = (val >>  8) & 0xff;
    p[1] = (val      ) & 0xff;
#endif
}