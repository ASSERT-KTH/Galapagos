asm_vperm1(block vec, block mask)
{
  block o;
  __asm__ volatile ("vperm %0,%1,%1,%2\n\t"
		    : "=v" (o)
		    : "v" (vec), "v" (mask));
  return o;
}