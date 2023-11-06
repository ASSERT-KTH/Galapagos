int32_t btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) 
{
    if (*xn < sizeof(uint32_t))
        return 0;

#if defined(BTC_BIGENDIAN)
    /** Read a 32-bit quantity in big-endian order */
    *zp = ((uint32_t)(*xp)[0] <<  24)
        | ((uint32_t)(*xp)[1] <<  16)
        | ((uint32_t)(*xp)[2] <<  8)
        | ((uint32_t)(*xp)[3] <<  0);
#else
    /** Read a 32-bit quantity in little-endian order */
    *zp = *(*xp) | (*(*xp + 1) << 8) | (*(*xp + 2) << 16) | (*(*xp + 3) << 24);
#endif

    /** Move the pointer by 4 */
    *xp += sizeof(uint32_t);
    *xn -= sizeof(uint32_t);

    return 1;
}