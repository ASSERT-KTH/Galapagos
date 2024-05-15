asm_ncipher_be(block b, block rk)
{
  block o;
  __asm__ volatile ("vncipher %0, %1, %2\n\t"
		    : "=v" (o)
		    : "v" (b), "v" (rk));
  return o;
}