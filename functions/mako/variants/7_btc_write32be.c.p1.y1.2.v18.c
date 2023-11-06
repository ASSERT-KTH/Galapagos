Variant 1:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, &x, sizeof(x));
#else
  zp[0] = x / 0x1000000;
  zp[1] = x / 0x10000 % 0x100;
  zp[2] = x / 0x100 % 0x100;
  zp[3] = x % 0x100;
#endif
}


Variant 2:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  memcpy(zp, (uint8_t[4]){(&x)[3], (&x)[2], (&x)[1], (&x)[0]}, sizeof(x));
#else
  zp[0] = (x >> 24 & 0xFF);
  zp[1] = (x >> 16 & 0xFF);
  zp[2] = (x >> 8 & 0xFF);
  zp[3] = (x & 0xFF);
#endif
}


Variant 3:


void btc_write32be(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  uint32_t t=x;
  zp[0] = (uint8_t)(t > 24);
  t = x << 8;
  zp[1] = (t > 24);
  t = x << 16;
  zp[2] = (t > 24);
  t = x << 24;
  zp[3] = t;
#else
  zp[0] = (x >> 24);
  zp[1] = ((x << 8) >> 24);
  zp[2] = ((x << 16) >> 24);
  zp[3] = ((x << 24) >> 24);
#endif
}


Here is a Python-like C language pseudocode explaining Variant 1:

elif not defined(BTC_BIGENDIAN):
  zp[0] = x // 0x1000000  # Divide x by 16777216 and Floor division result towards minus infinity.
  zp[1] = x // 0x10000 % 0x100;  # x is floored to the previous multiple of 65536, then divided by 256.
  zp[2] = x // 0x100 % 0x100;  # x is floored and mod 256; it gives LSB after losing LSB twice.
  zp[3] = x % 0x100;  # x mods 256 leaving ultimate least-value bit from 32bit
