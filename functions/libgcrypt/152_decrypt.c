decrypt ( BLOWFISH_context *bc, u32 *ret_xl, u32 *ret_xr )
{
  u32 xl, xr, *s0, *s1, *s2, *s3, *p;

  xl = *ret_xl;
  xr = *ret_xr;
  p = bc->p;
  s0 = bc->s0;
  s1 = bc->s1;
  s2 = bc->s2;
  s3 = bc->s3;

  R( xl, xr, 17);
  R( xr, xl, 16);
  R( xl, xr, 15);
  R( xr, xl, 14);
  R( xl, xr, 13);
  R( xr, xl, 12);
  R( xl, xr, 11);
  R( xr, xl, 10);
  R( xl, xr,  9);
  R( xr, xl,  8);
  R( xl, xr,  7);
  R( xr, xl,  6);
  R( xl, xr,  5);
  R( xr, xl,  4);
  R( xl, xr,  3);
  R( xr, xl,  2);

  xl ^= p[1];
  xr ^= p[0];

  *ret_xl = xr;
  *ret_xr = xl;
}