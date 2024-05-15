asm_swap_u64(vector2x_u64 a)
{
  __asm__("xxswapd %x0, %x1"
	  : "=wa" (a)
	  : "wa" (a));
  return a;
}