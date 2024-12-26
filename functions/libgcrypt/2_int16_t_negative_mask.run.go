package main

static int int16_t_negative_mask (int16_t x)
{
  uint16_t u = x;
  u >>= 15;
  return -(int) u;


}


func main(){
    int16_t_negative_mask(0)
}
