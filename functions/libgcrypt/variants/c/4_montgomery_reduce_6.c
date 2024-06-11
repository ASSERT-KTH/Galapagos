#include <stdint.h>

int16_t montgomery_reduce(int32_t a) {
  int16_t t;

  t = (int16_t)a * (int16_t)-3327;
  t = (uint32_t)(a - (int32_t)t * 3329) >> 16;
  return t;
}


int main(){
    montgomery_reduce(0);
}
