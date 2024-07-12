#include <stdio.h>
#include <strings.h>

int a;
short b = 5, c;
short l;

void empty();

int foo() {
  short e = -1;
  unsigned short f;
  char g = 25;
  long h = 0;
  if (a != 0) {
    h = -1;
    g = 0;
  }
  short i = ~g;
  unsigned j = g;
  f = (h | (i | (583 | j))) ^ ~(~(g & 5L) / e);
  if (b != 0) {
    c = 22 / (8UL - f);
    if (f > 0)
      putc('\0', stdout);
  }
  int k = h % c;
  
  short l = f ^ 5L;
  if (l != 0) {
    a = k;
  }

  if (a)
      return 1;
  return 0;
}


int main(){
    foo();
}
