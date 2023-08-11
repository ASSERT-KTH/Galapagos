Here is a function variant that maintains the integrity of the original function's behaviour also retaining its functionality.

void btc_uint32_write(uint8_t *zp, uint32_t x) { 
  
/*In some systems, making machine byte order checks at runtime can eliminate endianness conversion. 
  This could be very important in applications where performance is an issue. */
  const int num = 1;
  //#define BTC_BIGENDIAN (*(char *)&num == 0)
  
  //Using union to access number as bytes without breakig the strict aliasing rules
  union {
    unsigned char by[4];
    uint32_t u32;
  } data;
  data.u32 = x;
  
  if(*(char *)&num == 0){   //Big Endian
    *zp++ = data.by[3];
    *zp++ = data.by[2];
    *zp++ = data.by[1];
    *zp++ = data.by[0];
  }
  else{   //Little Endian
    memcpy(zp, &x, sizeof(x));
    zp += 4;
  }
}
  
This new variant eliminates need of a preprocessor macro (BTC_BIGENDIAN) and effectively emulates the same behaviour using runtime check hence accounting both big-endian systems and little-endian systems. It also encapsulates outcome in one-body if-block instead of relying on preprocessor directive thus maintaining function's functionality with a slight variation considering different system scenarios runtime.