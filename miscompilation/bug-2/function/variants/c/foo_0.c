#include <stdio.h>
#include <strings.h>

int a;
short b = 5, c;
short l;

void empty();

int foo(int f, int g) {
  if ((f - g) < 10000)
    return f;
  return f + (1 % -f);
}


int main(){
    foo(0,0);
}