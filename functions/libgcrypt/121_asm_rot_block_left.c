asm_rot_block_left(block a)
{
  block r;
  block zero = { 0, 0 };
  __asm__ volatile ("xxmrgld %x0, %x1, %x2"
		    : "=wa" (r)
		    : "wa" (a), "wa" (zero));
  return r;
}