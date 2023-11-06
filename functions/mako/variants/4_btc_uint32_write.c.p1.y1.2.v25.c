Here are some variants of the function which can do the equivalent job:

Transformation 1:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[0] = x >>  0;
  zp[1] = x >>  8;
  zp[2] = x >> 16;
  zp[3] = x >> 24;
#else
  *((uint32_t*)zp) = x;  
#endif
}

Transformation 2:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for(int i = 3; i >= 0; i--) {
    zp[i] = (x >> (8*(3-i))) & 0xFF;
  }
#else
  memcpy(zp, &x , sizeof(x));
#endif
}

Transformation 3:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for(int i = 0; i < 4; i++) {
    zp[i] = (x >> (8*i)) & 0xFF;
  }

#else
  nuint32_t* ptr = (nuint32_t*)zp;
  *ptr = x;  
#endif
}   

}
 

Transformation 4:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  zp[3] = (x >> 24) & 0xff; 
  zp[2] = (x >> 16) & 0xff;     
  zp[1] = (x >> 8)  & 0xff;     
  zp[0] = (x >> 0)  & 0xff; 

#else
  memcpy(zp, &x , sizeof(x));
#endif
}  

Please adapt the version you need according to your compiler optimization level and safety settings.