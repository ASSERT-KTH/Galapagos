bulk_ocb_prepare_L_pointers_array_blk16 (gcry_cipher_hd_t c,
                                         ocb_L_uintptr_t Ls[16], u64 blkn)
{
  unsigned int n = 16 - (blkn % 16);
  unsigned int i;

  for (i = 0; i < 16; i += 8)
    {
      Ls[(i + 0 + n) % 16] = (uintptr_t)(void *)c->u_mode.ocb.L[0];
      Ls[(i + 1 + n) % 16] = (uintptr_t)(void *)c->u_mode.ocb.L[1];
      Ls[(i + 2 + n) % 16] = (uintptr_t)(void *)c->u_mode.ocb.L[0];
      Ls[(i + 3 + n) % 16] = (uintptr_t)(void *)c->u_mode.ocb.L[2];
      Ls[(i + 4 + n) % 16] = (uintptr_t)(void *)c->u_mode.ocb.L[0];
      Ls[(i + 5 + n) % 16] = (uintptr_t)(void *)c->u_mode.ocb.L[1];
      Ls[(i + 6 + n) % 16] = (uintptr_t)(void *)c->u_mode.ocb.L[0];
    }

  Ls[(7 + n) % 16] = (uintptr_t)(void *)c->u_mode.ocb.L[3];
  return &Ls[(15 + n) % 16];
}