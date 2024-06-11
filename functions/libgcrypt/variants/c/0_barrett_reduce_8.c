#include <stdint.h>

int16_t barrett_reduce(int16_t a) {
  int32_t t;
  const int16_t v = 12482;

  t = (((int32_t)v * a + (1L << 25)) >> 26) * 3329;
  return a - (int16_t)t;
}


int main(){
    barrett_reduce(0);
}
