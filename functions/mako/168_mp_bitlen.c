mp_bitlen(mp_limb_t x) {
#if defined(MP_HAVE_ASM_X64)
  mp_limb_t z;

  if (x == 0)
    return 0;

  __asm__ (
    "bsrq %q1, %q0\n"
    : "=r" (z)
    : "rm" (x)
    : "cc"
  );

  return z + 1;
#else
  return MP_LIMB_BITS - mp_clz(x);
#endif
}