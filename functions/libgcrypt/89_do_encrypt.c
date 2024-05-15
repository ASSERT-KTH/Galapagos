do_encrypt ( BLOWFISH_context *bc, u32 *ret_xl, u32 *ret_xr )
{
  u32 xl, xr, *s0, *s1, *s2, *s3, *p;

  xl = *ret_xl;
  xr = *ret_xr;
  p = bc->p;
  s0 = bc->s0;
  s1 = bc->s1;
  s2 = bc->s2;
  s3 = bc->s3;

  R( xl, xr,  0);
  R( xr, xl,  1);
  R( xl, xr,  2);
  R( xr, xl,  3);
  R( xl, xr,  4);
  R( xr, xl,  5);
  R( xl, xr,  6);
  R( xr, xl,  7);
  R( xl, xr,  8);
  R( xr, xl,  9);
  R( xl, xr, 10);
  R( xr, xl, 11);
  R( xl, xr, 12);
  R( xr, xl, 13);
  R( xl, xr, 14);
  R( xr, xl, 15);

  xl ^= p[16];
  xr ^= p[16+1];

  *ret_xl = xr;
  *ret_xr = xl;
}