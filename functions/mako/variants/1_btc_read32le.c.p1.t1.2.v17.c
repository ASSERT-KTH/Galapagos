The function btc_read32le reads 4 bytes from the xp array and interprets them as a 32 bit wide little endian formatted integer value. If the macro BTC_BIGENDIAN is defined it adjusts for this with byte shifts and OR operations. In other situations it simply copies the 4 byte sequence directly.

The same functionality could also be achieved by directly repackaging the bytes without using a memcpy type method. The reinterpret cast would be replaced with a pointer casting alternative in such a program variation:


btc_read32le(const uint8_t *xp){
#if defined(BTC_BIGENDIAN)
  return ((uint32_t)xp[0] <<  0)
       | ((uint32_t)xp[1] <<  8)
       | ((uint32_t)xp[2] << 16)
       | ((uint32_t)xp[3] << 24);
#else
  // re-interpret the input data as a pointer to uint32_t and dereference it
  return *(uint32_t*)xp;
#endif
}


Take note that using such a pointer cast is only viable in strictly controlled environments and if one can guarantee alignment. This has potential exceptions that could occur due to incorrect alignment as some architectures will not allow it.