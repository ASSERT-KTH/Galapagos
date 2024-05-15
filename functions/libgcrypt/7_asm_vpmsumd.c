asm_vpmsumd(block a, block b)
{
  block r;
  __asm__ volatile ("vpmsumd %0, %1, %2"
		    : "=v" (r)
		    : "v" (a), "v" (b));
  return r;
}