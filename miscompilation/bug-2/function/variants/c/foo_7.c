#include <stdio.h>
#include <strings.h>

int a;
short b = 5, c;
short l;

void empty();

int foo(int f, int g) {
  int result = f;
  if (f - g >= 10000) {
    result = f + 1 % -f;
  }
  return result;
}


int main(){
    foo(0,0);
}
