int printf(const char *, ...);
int a;
short b = 5, c;
int foo() {
  short e = -1;
  char g = 25;
  long h = a ? -1 : 0;
  if(a) g = 0;
  unsigned short f;
  short i = ~g;
  unsigned j = g;
  if (b) {
    f = (h | (i | (583 | j))) ^ ~(~(g & 5L) / e);
    c = 22 / (8UL - f);
    if (f) printf("0\n");
  } 
  short l = f ^ 5L;
  if (l) a = h % c;
  return 0;
}

int main(){
    foo();
}

