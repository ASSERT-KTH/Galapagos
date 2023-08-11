Here is a possible variant of the function that maintains the same functionality:

int32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
    uint32_t temp=0;
    for(int i=0;i<4;i++)
    {
        temp = temp << 8;  
	    temp = temp | xp[i];
    }
    return temp;
#else
  return xp[0]
       | (xp[1] << 8)
       | (xp[2] << 16)
       | (xp[3] << 24);
#endif
}