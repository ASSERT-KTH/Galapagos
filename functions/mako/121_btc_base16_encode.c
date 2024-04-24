btc_base16_encode(char *zp, const uint8_t *xp, size_t xn) {
  while (xn--) {
    int ch = *xp++;

    *zp++ = base16_charset[ch >> 4];
    *zp++ = base16_charset[ch & 15];
  }

  *zp = '\0';
}