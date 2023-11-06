This variation of the function follows similar logic while still maintaining its original behaviour, but skips using memcpy and takes advantage of bit manipulation technics whether BTC_BIGENDIAN is defined or not.


uint32_t btc_read32le(const uint8_t *xp) {
#if defined(BTC_BIGENDIAN)
  uint32_t z = xp[3];
  z = (z << 8) | xp[2];
  z = (z << 8) | xp[1];
  z = (z << 8) | xp[0];
  return z;
#else
  uint32_t z = xp[0];
  z = (z << 8) | xp[1];
  z = (z << 8) | xp[2];
  z = (z << 8) | xp[3];
  return z;
#endif
}


Note:- If you're writing hyper-optimised code for a specific environment, definitely check if memcpy outperforms explicit copying via assignments on that platform.