store_32_le (unsigned int val, void *vp)
{
    unsigned char *p = (unsigned char *) vp;
#if defined(__GNUC__) && defined(K5_LE) && !defined(__cplusplus)
    PUT(32,p,val);
#elif defined(__GNUC__) && defined(K5_BE) && defined(SWAP32) && !defined(__cplusplus)
    PUTSWAPPED(32,p,val);
#else
    p[3] = (val >> 24) & 0xff;
    p[2] = (val >> 16) & 0xff;
    p[1] = (val >>  8) & 0xff;
    p[0] = (val      ) & 0xff;
#endif
}