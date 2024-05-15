vec_load_he(unsigned long offset, const unsigned char *ptr)
{
  block vec;
  /* GCC vec_vsx_ld is generating two instructions on little-endian. Use
   * lxvd2x directly instead. */
#if __GNUC__ >= 4
  if (__builtin_constant_p (offset) && offset == 0)
    __asm__ volatile ("lxvd2x %x0, 0, %1\n\t"
		    : "=wa" (vec)
		    : "r" ((uintptr_t)ptr)
		    : "memory", "r0");
  else
#endif
    __asm__ volatile ("lxvd2x %x0, %1, %2\n\t"
		      : "=wa" (vec)
		      : "r" (offset), "r" ((uintptr_t)ptr)
		      : "memory", "r0");
  return vec;
}