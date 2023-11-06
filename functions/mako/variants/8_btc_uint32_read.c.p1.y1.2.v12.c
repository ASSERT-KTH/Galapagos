
void btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn >= 4)
  {
#if defined(BTC_BIGENDIAN)
    *zp = ((uint32_t)(*xp)[0] <<  0)
        | ((uint32_t)(*xp)[1] <<  8)
        | ((uint32_t)(*xp)[2] << 16)
        | ((uint32_t)(*xp)[3] << 24);
#else
    *zp = *((uint32_t*)(*xp));
#endif

    *xp += 4;
    *xn -= 4;
  }
}



void btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn)
{
    if (*xn < sizeof(uint32_t))
        return;

    uint32_t z = 0;
#if BTC_BIGENDIAN == 1
    z |= ((uint32_t)(*xp)[3] << 24);
    z |= ((uint32_t)(*xp)[2] << 16);
    z |= ((uint32_t)(*xp)[1] << 8);
    z |= ((uint32_t)(*xp)[0]);
#else
    memcpy(&z, *xp, sizeof(uint32_t));
#endif

    *zp = z;
    *xp += sizeof(uint32_t);
    *xn -= sizeof(uint32_t);
}



void btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn >= 4)
  {
    if (btc_is_bigendian()) {
  *zp = ((uint32_t)(*xp)[0] <<  0)
    | ((uint32_t)(*xp)[1] <<  8)
    | ((uint32_t)(*xp)[2] << 16)
    | ((uint32_t)(*xp)[3] << 24);
    }
    else {
#if !defined(BTC_BIGENDIAN)
      memcpy(zp, *xp, sizeof(*zp));
#endif
    }

    *xp += 4;
    *xn -= 4;
  }
}



btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) 
{
    if (*xn >= 4)
    {
#if defined(BTC_BIGENDIAN)
        *zp =  ((*xp)[0] )
            | ((*xp)[1] <<  8)
            | ((*xp)[2] << 16)
            | ((*xp)[3] << 24);
#else
       *zp = (*(uint32_t*)(*xp));
#endif
        *xp += 4;
        *xn -= 4;

        return ;
    }
    return ;
}
