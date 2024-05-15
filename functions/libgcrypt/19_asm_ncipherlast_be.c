asm_ncipherlast_be(block b, block rk)
{
  block o;
  __asm__ volatile ("vncipherlast %0, %1, %2\n\t"
		    : "=v" (o)
		    : "v" (b), "v" (rk));
  return o;
}