aria_add_round_key(u32 *rk, u32 *t0, u32 *t1, u32 *t2, u32 *t3)
{
  *t0 ^= rk[0];
  *t1 ^= rk[1];
  *t2 ^= rk[2];
  *t3 ^= rk[3];
}