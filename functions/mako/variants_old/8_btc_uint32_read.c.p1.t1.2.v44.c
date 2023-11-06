Here's the variation which checks the Endianness at runtime rather than compile time:


btc_uint32_read(uint32_t *zp, const uint8_t **xp, size_t *xn) {
  if (*xn < 4)
    return 0;

  union ot_32_bit_endian_test {
    uint8_t byte_field[4];
    uint32_t uint_field;
  };

  // check limit condition for our test struct array:
  union ot_32_bit_endian_test ot_check = { .byte_field = { 1, 0, 0, 0 } };

  // If the uint_field of the struct equals 1, we are on Little Endian System.
  // So we memcpy directly otherwise we manually build uint32 on Big Endian System.
  if (ot_check.uint_field == 1) {
    memcpy(zp, *xp, sizeof(*zp));
  } else {
    *zp = ((uint32_t)(*xp)[0] <<  0)
        | ((uint32_t)(*xp)[1] <<  8)
        | ((uint32_t)(*xp)[2] << 16)
        | ((uint32_t)(*xp)[3] << 24);
  }

  *xp += 4;
  *xn -= 4;

  return 1;
}

This variant calculates the Endianness on each function call. However, behavior changes should hardly be noticeable in terms of runtime. This is attributed to the efficiency of modern processors' branch predictors. They can accurately predict the always equal if-condition and prepare (nearly) optimal instruction caching and execution.