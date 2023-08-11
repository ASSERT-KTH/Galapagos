The variant can involve a small swap in the positioning of updating the xp and xn pointers and conditions for checking endianess. Here is the variant considering these:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

  *xp += 4;
  *xn -= 4;

#if defined(BTC_BIGENDIAN)
  *zp = ((uint32_t)(*xp)[-4] <<  0)
      | ((uint32_t)(*xp)[-3] <<  8)
      | ((uint32_t)(*xp)[-2] << 16)
      | ((uint32_t)(*xp)[-1] << 24);
#else
  memcpy(zp, *xp - 4, sizeof(*zp));
#endif

  return 1;
}

Remember that changing the execution order implies in changing the used logics as well.
Thus, one has to decrease the pointer value considering that _xp initially pointed to beyond used values_. Similarly, the memcpy function is now oriented to copy from the block that is 4 positions more to the left with respect to where _xp points. 

The control logic remains the same. In summary, this new routine seems to do what exactly as the initial one but the course taken differs as described. 
Please review this and ensure it suits the desired data path alternatives for handling big-endian models and requirements imposed elsewhere in your code for your application.