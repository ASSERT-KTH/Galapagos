Variant 1:

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)(xp[0]) | ((uint32_t)xp[1] <<  8) | ((uint32_t)xp[2] << 16) | ((uint32_t)xp[3] << 24));
#else  
  uint32_t z;
  memmove(&z, xp, sizeof(z));
  return z;
#endif
}


Variant 2:

btc_read32le(const uint8_t *xp) {
  #if defined(BTC_BIGENDIAN)
    uint32_t result = xp[0];
    result |= xp[1] << 8;
    result |= xp[2] << 16;
    result |= xp[3] << 24;
    return result;
  #else
    uint32_t output;
    unsigned const char* pin = (unsigned const char*)xp;
    output = *pin++;
    output |= (*pin++) << 8;
    output |= (*pin++) << 16;
    output |= (*pin++) << 24;
    return output;
  #endif
}


Variant 3:

btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t ret_val = 0;
  ret_val = (ret_val << 8) | xp[0];
  ret_val = (ret_val << 8) | xp[1];
  ret_val = (ret_val << 8) | xp[2];
  ret_val = (ret_val << 8) | xp[3];
  return ret_val;
#else
  uint32_t return_variable; 
  memcpy(&return_variable, xp, sizeof(return_variable)); 
  return return_variable;
#endif
}
