asm_xor(block a, block b)
{
  block res;
  __asm__ volatile ("vxor %0,%1,%2\n\t"
		    : "=v" (res)
		    : "v" (a), "v" (b));
  return res;
}