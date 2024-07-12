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
  if (a) {
    h = -1;
    g = 0;
  }
  short i = ~g;
  unsigned j = (unsigned) g;
  if (b) {
    f = (h | (i | (583 | j))) ^ ~(~(g & 5L) / e);
    c = 22 / (8UL - f);
    if (f > 0)
      ffs(f);
  }
  int k = h % c;
  if ((f ^ 5L) != 0)
    a = k;
  return a != 0 ? 1 : 0;
}


int main(){
    foo();
}
