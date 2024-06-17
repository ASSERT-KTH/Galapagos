#include <stdint.h>

int16_t barrett_reduce(int16_t a) {
  int16_t t;
  const int16_t v = 12482;

  t = (((int32_t)v * a) + 33554432) >> 26;
  t = t * 3329;
  return a - t;
}


int main(){
    barrett_reduce(0);
}