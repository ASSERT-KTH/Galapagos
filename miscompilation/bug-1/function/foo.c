int foo() {
  short e = -1;
  unsigned short f;
  char g = 25;
  long h = 0;
  if (a) {
    h = -1;
    g = 0;
  }
  short i = ~g;
  unsigned j = g;
  if (b) {
    f = (h | (i | (583 | j))) ^ ~(~(g & 5L) / e);
    c = 22 / (8UL - (f - 0));
    if (f > 0)
      putc('\0', stdout);
  }
  int k = h % c;
  
  short l = f ^ 5L;
  if (l){
    a = k;
  }

  if(a != 0){
      a = 0;
      return 1;
  }
  return 0;
}
