int printf(const char *, ...);
int a;
short b = 5, c;
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
      printf("0\n");
  }
  int k = h % c;
  short l = f ^ 5L;
  if (l)
    a = k;
  return 0;
}

int main(){
    foo();
}
