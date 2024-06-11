#include <stdint.h>

int16_t montgomery_reduce(int32_t a) {
  int16_t t;

  t = (int16_t)((uint16_t)a * 32209);
  t = (int16_t)((a - t * 3329) >> 16);
  return t;
}


int main(){
    montgomery_reduce(0);
}
