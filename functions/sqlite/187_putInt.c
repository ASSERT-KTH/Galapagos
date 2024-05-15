static void putInt(unsigned int v, char **pz){
  static const char zDigits[] =
    "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz~";
  /*  123456789 123456789 123456789 123456789 123456789 123456789 123 */
  int i, j;
  char zBuf[20];
  if( v==0 ){
    *(*pz)++ = '0';
    return;
  }
  for(i=0; v>0; i++, v>>=6){
    zBuf[i] = zDigits[v&0x3f];
  }
  for(j=i-1; j>=0; j--){
    *(*pz)++ = zBuf[j];
  }
}