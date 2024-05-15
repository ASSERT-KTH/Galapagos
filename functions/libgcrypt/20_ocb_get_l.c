ocb_get_l (gcry_cipher_hd_t c, u64 n)
{
  unsigned long ntz;

#if ((defined(__i386__) || defined(__x86_64__)) && __GNUC__ >= 4)
  /* Assumes that N != 0. */
  asm ("rep;bsfl %k[low], %k[ntz]\n\t"
        : [ntz] "=r" (ntz)
        : [low] "r" ((unsigned long)n)
        : "cc");
#else
  ntz = _gcry_ctz (n);
#endif

  return c->u_mode.ocb.L[ntz];
}