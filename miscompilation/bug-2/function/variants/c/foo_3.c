#include <stdio.h>
#include <strings.h>

int a;
short b = 5, c;
short l;

void empty();

int foo(int f, int g) {
  int diff = f - g;
  if (diff < 10000)
    return f;
  int modulus = 1 % -f;
  return f + modulus;
}


int main(){
    foo(0,0);
}
