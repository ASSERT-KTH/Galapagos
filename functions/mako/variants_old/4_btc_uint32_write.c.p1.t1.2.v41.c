Here is a program that does a similar thing:


void btc_uint32_write(uint8_t *zp, uint32_t x) {
#if defined(BTC_BIGENDIAN)
  for(int i = 0; i < 4; i++) {
    *(zp+i) = x >> (8*i);
  }
#else
  uint32_t *pz = (uint32_t *)zp;
  *pz = x;
  zp += 4;
#endif
}


Observe that
1) For a Big-Endian machine, instead of using pointer cast and directly cast the byte pointer to an uint32_t pointer that perhaps unhealthy for some machine architecture, we scan through each byte in the `btc_uint32_write` variable 'x', moving right by 8*i bits each time, and then dumped into zp at (8*i)-th position.   
   
2) For a Little-Endian machine, we are just copying the chunk of memory into zp and move zp by 4 bytes length. Please be cautious of this method as we are assuming that byte reverse is not needed here, it will behave wrong on a Big-Endian machine. I suppose this method should be fine given most of the popular platforms are Little-Endian, like X86 and ARM (in its little-endian mode). 

Please run and test the program thoroughly before adapting it to real-world situations.  
  

Assumption: This operation will be environment-dependent, as memcpy does not complete control over the direction in which they copy bytes. In programs where this distinction matters, you should only copy overlapping memory regions with raw memory copying functions (e.g., memcpy(), memmove()), only when you know the memory region and the CPU architecture your code will right run in (either Little-Big endian) and correct functions to do it exist on your specific platforms.