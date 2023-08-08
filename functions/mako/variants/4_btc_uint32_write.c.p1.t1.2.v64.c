Here is a function that maintains the original function signatures and does not employ the use of any helper functions. Besides this, it guarantees that the output renders the same behaviour as the initial function:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
  union TO_ENDIAN {
    uint32_t number;
    uint8_t bytes[4];
  };
  union TO_ENDIAN endian_converter;
  
  endian_converter.number = x;

#ifndef BTC_BIGENDIAN
  for (int i = 3; i >= 0 ; i--){ 
    *zp++ = endian_converter.bytes[i]; 
  }
#else  
  for (int i = 0; i < 4; i++){ 
    *zp++ = endian_converter.bytes[i];  
  }
#endif

}

The modified or Variation function holds the fastidious behaviour as the original will. The difference can be perceived in the implementation method, compatibility with certain or particular platforms, and perhaps resource management on different hardware set up or constraints.
Bear in mind that this modification was made assuming the system uses little-endian data format memory. If your system instigates big-endian format, reverse the byte order during memcpy.