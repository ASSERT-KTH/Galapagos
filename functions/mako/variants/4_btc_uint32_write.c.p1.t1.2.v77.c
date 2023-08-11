Here's the modified version:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
   #if defined(BTC_BIGENDIAN)
   zp[0] = (uint8_t)(x >>  0);
   zp[1] = (uint8_t)(x >>  8);
   zp[2] = (uint8_t)(x >> 16);
   zp[3] = (uint8_t)(x >> 24);
   #else
   uint32_t* p = (uint32_t*)zp;
   *p = x;
   #endif
}

The original implementation returns updated pointer, but in most situations function returning value is not called in the original version; thus same functionality is kept in this modification although I removed return statement. 

In BTC_BIGENDIAN part, pointer incrementing is replaced by direct addressing which could be safer in some contexts. 

For the #else part, type casting is done and value of x is assigned directly to pointer. Simply for both the variations of condition code looks clean and more readabilty is achieved.