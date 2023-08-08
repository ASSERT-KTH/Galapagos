uint32_t btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) 
{
    if (*xn < sizeof(*zp))
        return 0;
        
  #if defined(BTC_BIGENDIAN)
    for(int i = 0; i < sizeof(*zp); i++)
        *zp |= (uint32_t)(*xp)[i] << (8 * i);
  #else
    for(int i = sizeof(*zp); i > 0; i--)
        *zp |= (uint32_t)(*xp)[i - 1] << (8 * (i - 1));
  #endif

    *xp += sizeof(*zp);
    *xn -= sizeof(*zp);

    return 1;
}
This version uses loop to compose an integer structure in little endian or big endian according to the defined macro BTC_BIGENDIAN. */
