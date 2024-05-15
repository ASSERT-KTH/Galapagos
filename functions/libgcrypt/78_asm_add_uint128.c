asm_add_uint128(block a, block b)
{
  block res;
  __asm__ volatile ("vadduqm %0,%1,%2\n\t"
		    : "=v" (res)
		    : "v" (a), "v" (b));
  return res;
}