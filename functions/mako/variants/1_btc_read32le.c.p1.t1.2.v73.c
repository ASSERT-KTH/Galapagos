uint32_t btc_read32le(const uint8_t *xp)
{
  #if defined(BTC_BIGENDIAN) 

    uint32_t result = 0;

    int index;
    const int length = 4;

    for (index = 0; index < length; index++) 
    {
        result |= ((uint32_t)xp[index] << (8 * index));
    }

    return result;

  # else 

    uint32_t z;
  
    for(int offset = 3, i = 0; offset >= 0; offset--, i++)
        ((char*)&z)[offset] = xp[i];
      
    return z;

  # endif
}