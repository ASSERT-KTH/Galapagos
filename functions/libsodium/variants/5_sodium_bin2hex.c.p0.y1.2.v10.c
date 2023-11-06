char* sodium_bin2hex(char *const hex, const size_t hex_maxlen, 
                      const unsigned char *const bin, const size_t bin_len)
{
   size_t i;
   static const char hex_chars[] = "0123456789abcdef";

   if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2) {
        sodium_misuse();
   }

   for (i = 0; i < bin_len; ++i) {
        hex[i * 2] = hex_chars[bin[i] >> 4];
        hex[i * 2 + 1] = hex_chars[bin[i] & 0x0f];
   }

   hex[i * 2] = '\0';

   return hex;
}