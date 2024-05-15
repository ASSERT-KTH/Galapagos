aes_ocb_get_l (gcry_cipher_hd_t c, u64 n)
{
  unsigned long ntz;

  /* Assumes that N != 0. */
  asm ("rep;bsfl %k[low], %k[ntz]\n\t"
        : [ntz] "=r" (ntz)
        : [low] "r" ((unsigned long)n)
        : "cc");

  return c->u_mode.ocb.L[ntz];
}