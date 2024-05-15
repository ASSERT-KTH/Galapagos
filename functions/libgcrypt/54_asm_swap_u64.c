asm_swap_u64(block a)
{
  block r;
  __asm__ volatile ("xxswapd %x0, %x1"
		    : "=wa" (r)
		    : "wa" (a));
  return r;
}