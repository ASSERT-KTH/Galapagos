Variant 1: Using For Loop Instead of While

char* sodium_bin2hex(char *const hex, const size_t hex_maxlen,
       	        const unsigned char* const bin, const size_t bin_len) {
   unsigned int x;
   int b, c;

   if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
       sodium_misuse();
   }
   for (size_t i = 0; i < bin_len; i++) {
       c = bin[i] & 0xf;
       b = bin[i] >> 4;
       x = (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U)) << 8 |
           (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U));
       hex[i * 2U] = (char) x;
       x >>= 8;
       hex[i * 2U + 1U] = (char) x;
   }
   hex[bin_len * 2U] = 0U;

   return hex;
}


Variant 2: Using Multiplication in Increment

char* sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len) {
   size_t i = (size_t) 0U;
   unsigned int x;
   int b, c;

   if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
       sodium_misuse();
   }
   while (i < bin_len) {
       c = bin[i] & 0xf;
       b = bin[i] >> 4;
       x = (unsigned char)(87U + c + (((c - 10U) >> 8) & ~38U)) * 256U |
           (unsigned char)(87U + b + (((b - 10U) >> 8) & ~38U));
       hex[i * 2U] = (char)x;
       x = x / 256U;
       hex[(i * 2U) + 1U] = (char)x;
       i++;
   }
   hex[(bin_len * 2U)] = 0U;

   return hex;
}


Variant 3: Declaring Variables Inside Loop

char* sodium_bin2hex(char *const hex, const size_t hex_maxlen,
               const unsigned char *const bin, const size_t bin_len) {
   if (bin_len >= SIZE_MAX / 2 || hex_maxlen <= bin_len * 2U) {
       sodium_misuse();
   }
   for (size_t i = 0; i < bin_len; ++i) {
       int c = bin[i] & 0xf;
       int b = bin[i] >> 4;
       unsigned int x = (unsigned char)(87U + c + (((c - 10U) >> 8) & ~38U)) << 8 |
                        (unsigned char)(87U + b + (((b - 10U) >> 8) & ~38U));
       hex[i * 2U] = (char)x;
       x >>= 8;
       hex[i * 2U + 1U] = (char)x;
   }
   hex[bin_len * 2U] = 0U;

   return hex;
}
