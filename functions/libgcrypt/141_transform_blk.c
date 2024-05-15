transform_blk ( void *ctx, const unsigned char *data )
{
  TIGER_CONTEXT *hd = ctx;
  u64 a,b,c,aa,bb,cc;
  u64 x[8];
  int i;

  for ( i = 0; i < 8; i++ )
    x[i] = buf_get_le64(data + i * 8);

  /* save */
  a = aa = hd->a;
  b = bb = hd->b;
  c = cc = hd->c;

  pass( a, b, c, x, 5);
  key_schedule( x );
  pass( c, a, b, x, 7);
  key_schedule( x );
  pass( b, c, a, x, 9);

  /* feedforward */
  a ^= aa;
  b -= bb;
  c += cc;
  /* store */
  hd->a = a;
  hd->b = b;
  hd->c = c;

  return /*burn_stack*/ 21*8+11*sizeof(void*);
}