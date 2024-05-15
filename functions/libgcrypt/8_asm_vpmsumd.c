asm_vpmsumd(vector2x_u64 a, vector2x_u64 b)
{
  __asm__("vpmsumd %0, %1, %2"
	  : "=v" (a)
	  : "v" (a), "v" (b));
  return a;
}