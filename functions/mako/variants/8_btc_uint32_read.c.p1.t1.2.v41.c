Here's a function that meets your requirements:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < sizeof(*zp))
    return 0;

#if defined(BTC_BIGENDIAN)
  *zp = ((*xp)[0])
      | ((*xp)[1] << 8)
      | ((*xp)[2] << 16)
      | ((*xp)[3] << 24);
#else
  zp[0]=xp[0][3];
  zp[1]=xp[0][2];
  zp[2]=xp[0][1];
  zp[3]=xp[0][0];
#endif 

  *xp += sizeof(*zp);
  *xn -= sizeof(*zp);

  return 1;
}

Slight changes have been made in two places:

1) I replaced the hard-coded "4" with "sizeof(*zp)" because it directly relates to the size of the uint32_t object zp points to. It also makes the function more maintainable and easier to understand.

2) The argument de-referencing has been modified during the copying process in the else part of condition thus adding to change while still performing the copying operation from *xp to zp, taking endianess into account. Although, the functionality remains the same while providing a variant.