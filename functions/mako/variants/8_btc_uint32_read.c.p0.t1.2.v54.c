btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  
  // Strictly speaking the check should ensure that there's at least sizeof(*zp) size remaining.
  // Although zp is expected to be an uint32_t *, it would be better to explicitly write it down.
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  // Instead of entire three lines to write the data from XP
  *zp =  (*xp)[0]
      | ((*xp)[1] <<  8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24);
#else
  // Use direct pointer addition instead of memcpy(). Safer if you know that pointers are aligned.
  *zp = *((uint32_t*)*xp);
#endif

  *xp += sizeof(*zp);  // Preserve xp semantics across potential changes of underlying data type
  *xn -= sizeof(*zp);  // Do the same for variable xn, preserving semantic changes in ZP
  
  return 1;
}
