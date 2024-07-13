#include <stdio.h>
#include <strings.h>

int a;
short b = 5, c;
short l;

void empty();

int foo() {
  short e = -1;
  char g = 25;
  long h = a ? -1 : 0;
  if (a) {
    g = 0;
  }
  short i = ~g;
  unsigned j = g;
  unsigned short f;
  if (b) {
    f = (h | (i | (583 | j))) ^ ~(~(g & 5L) / e);
    c = 22 / (8UL - f);
    if (f > 0)
      putc('\0', stdout);
  }
  int k = h % c;
  
  short l = f ^ 5L;
  if (l) {
    a = k;
  }

  if(a != 0) {
      a = 0;
      return 1;
  }
  return 0;
}


int main(){
    foo();
}
