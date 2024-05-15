asm_xor(block a, block b)
{
  block r;
  __asm__ volatile ("xxlxor %x0, %x1, %x2"
		    : "=wa" (r)
		    : "wa" (a), "wa" (b));
  return r;
}