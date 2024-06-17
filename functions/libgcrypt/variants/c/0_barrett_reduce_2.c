#include <stdint.h>

int16_t barrett_reduce(int16_t a) {
  int16_t t;
  const int16_t v = 12482;

  t = ((long long)v * a + 33554432LL) >> 26;
  t = 3329 * t;
  return a - t;
}


int main(){
    barrett_reduce(0);
}