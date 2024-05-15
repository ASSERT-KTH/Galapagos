static void hash_step(const unsigned char *data,  unsigned int len){
  unsigned int i, j;

  j = g.cx.count[0];
  if( (g.cx.count[0] += len << 3) < j ){
    g.cx.count[1] += (len>>29)+1;
  }
  j = (j >> 3) & 63;
  if( (j + len) > 63 ){
    (void)memcpy(&g.cx.buffer[j], data, (i = 64-j));
    SHA1Transform(g.cx.state, g.cx.buffer);
    for(; i + 63 < len; i += 64){
      SHA1Transform(g.cx.state, &data[i]);
    }
    j = 0;
  }else{
    i = 0;
  }
  (void)memcpy(&g.cx.buffer[j], &data[i], len - i);
}