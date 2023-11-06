I. Changed indexing to pointer arithmetic:

char* sodium_bin2hex(char *const hex, const size_t hex_maxlen,
                     const unsigned char *const bin, const size_t bin_len)
{
  unsigned char *p = hex;
  unsigned const char *q = bin;
  unsigned int x;
  int c, b;

  if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
    sodium_misuse();
  }
  for (; q < bin + bin_len; p += 2, ++q) {
    c = *q & 0xf;
    b = *q >> 4;
    x = (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U)) << 8 |
         (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U));
    *p = x;
    x >>= 8;
    *(p + 1) = x;
  }
 *p = 0U;

  return hex;
}


II. Using for loop instead of while:

char* sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len)
{
    size_t       i;
    unsigned int x;
    int          b;
    int          c;

    if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
        sodium_misuse();
    }
    for(i = 0; i < bin_len; i++) {
        c = bin[i] & 0xf;
        b = bin[i] >> 4;
        x = (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U)) << 8 |
            (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U));
        hex[i * 2U] = (char) x;
        x >>= 8;
        hex[i * 2U + 1U] = (char) x;
    }
    hex[i * 2U] = 0U;

    return hex;
}
