Sure, Here is a variation that maintains original functionality.


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

#if defined(BTC_BIGENDIAN)
  (*zp) = (uint32_t)(((*xp)[0] <<  24) | ((*xp)[1] << 16) | ((*xp)[2] << 8) | ((*xp)[3]));
#else
  (*zp) = (uint32_t)(((*xp)[3] <<  24) | ((*xp)[2] << 16) | ((*xp)[1] << 8) | ((*xp)[0]));
#endif

  (*xp) += 4;
  (*xn) -= 4;

  return 1;
}


Note that this version behaves exactly the same way as the first implementation. It reads a 32-bit unsigned key from `xp`, fills it into `zp`, and moves forward the input pointer `xp` by four bytes. All these deepdends on the endianness of the system it is being runned.
This version differs from the first one only in the way big-endian association is made: instead of considering bytes as ascending (from right to left), it considers them importing informations from left-to-right. Also exact same equivalent has been created for the little endian function using direct byte access instead of memcpy for a 4 byte moves it achieves same compiled assembly sequence.