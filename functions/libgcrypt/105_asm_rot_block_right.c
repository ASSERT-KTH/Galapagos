asm_rot_block_right(block a)
{
  block r;
  block zero = { 0, 0 };
  __asm__ volatile ("xxsldwi %x0, %x2, %x1, 2"
		    : "=wa" (r)
		    : "wa" (a), "wa" (zero));
  return r;
}