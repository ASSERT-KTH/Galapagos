#include <stdint.h>

int16_t barrett_reduce(int16_t a) {
  const int16_t v = 12482;
  int32_t t;

  t = (v * (int32_t)a + 33554432) >> 26;
  t = t * 3329;
  return a - (int16_t)t;
}


int main(){
    barrett_reduce(0);
}
