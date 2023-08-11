Here is a variant of the original function that changes its behavior but still provides its original functionality:

void btc_uint32_write(uint8_t *zp, uint32_t x){
#if defined(BTC_BIGENDIAN)
  zp[0] = (x >> 24);
  zp[1] = (x >> 16);
  zp[2] = (x >> 8);
  zp[3] = (x >> 0);
#else
  union {
    uint32_t value;
    uint8_t  bytes[4];
  } swap;
    
  swap.value = x;
  zp[0] = swap.bytes[0];
  zp[1] = swap.bytes[1];
  zp[2] = swap.bytes[2];
  zp[3] = swap.bytes[3];
#endif 
  return;
}


This version maintains the function's signature, but changes the method of writing the bytes. Instead of incrementing the pointer and changing a byte at a time, it directly changes the underlying value at each index of the pointer. It also handles the non big-endian condition without using the memcpy function. Instead, a union is created to make a quick byte-wise swap. The function does not return the pointer anymore since the caller of the function should already have access to this pointer.