#include <stdint.h>

int16_t barrett_reduce(int16_t a) {
  const int16_t v = 12482;
  int32_t t;

  t = (((int32_t)v * a) >> 26) * 3329;
  return a - t;
}


int main(){
    barrett_reduce(0);
}