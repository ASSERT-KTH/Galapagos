static void readCoord(u8 *p, RtreeCoord *pCoord){
  assert( FOUR_BYTE_ALIGNED(p) );
#if SQLITE_BYTEORDER==1234 && MSVC_VERSION>=1300
  pCoord->u = _byteswap_ulong(*(u32*)p);
#elif SQLITE_BYTEORDER==1234 && GCC_VERSION>=4003000
  pCoord->u = __builtin_bswap32(*(u32*)p);
#elif SQLITE_BYTEORDER==4321
  pCoord->u = *(u32*)p;
#else
  pCoord->u = (
    (((u32)p[0]) << 24) + 
    (((u32)p[1]) << 16) + 
    (((u32)p[2]) <<  8) + 
    (((u32)p[3]) <<  0)
  );
#endif
}