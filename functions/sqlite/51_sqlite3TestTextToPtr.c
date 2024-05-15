void *sqlite3TestTextToPtr(const char *z){
  void *p;
  u64 v;
  u32 v2;
  if( z[0]=='0' && z[1]=='x' ){
    z += 2;
  }
  v = 0;
  while( *z ){
    v = (v<<4) + testHexToInt(*z);
    z++;
  }
  if( sizeof(p)==sizeof(v) ){
    memcpy(&p, &v, sizeof(p));
  }else{
    assert( sizeof(p)==sizeof(v2) );
    v2 = (u32)v;
    memcpy(&p, &v2, sizeof(p));
  }
  return p;
}