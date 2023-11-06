Variant 1:


uint8_t *btc_uint32_write(uint8_t *zp, uint32_t x) {
  #if defined(BTC_BIGENDIAN)
    zp[0] = x; 
	x >>= 8;
	zp[1] = x; 
	x >>= 8;
	zp[2] = x;
	x >>= 8;
	zp[3] = x;
    return zp + 4;
  #else
    uint32_t* px = (uint32_t*)zp;
	*px = x;
    return zp + 4;
  #endif
}


Variant 2:


uint8_t *btc_uint32_write(uint8_t *zp, uint32_t x) {
  #if defined(BTC_BIGENDIAN)
     uint32_t mask = 0x000000ff;
     for(int i = 0; i < 4; i++){
        zp[i] = (x & mask) >> 8*i;
	mask <<= 8;
     }
     return zp + 4;
  #else 
    *(uint32_t*)zp = x;
    return zp + 4;
  #endif
}


Variant 3: 


uint8_t *btc_uint32_write(uint8_t *zp, uint32_t x) {
    #if defined(BTC_BIGENDIAN)
        for(int i = 3 ;i >=0 ; i--){
            zp[i] = x & 0xff;
            x >>= 8;
        }
        return zp + 4;
    #else
        *(uint32_t*)zp = x;
        return zp + 4;
    #endif
}
