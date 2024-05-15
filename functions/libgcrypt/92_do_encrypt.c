do_encrypt (const SEED_context *ctx, byte *outbuf, const byte *inbuf)
{
  u32 x1, x2, x3, x4;
  union wordbuf t0, t1;

  x1 = GETU32 (inbuf);
  x2 = GETU32 (inbuf+4);
  x3 = GETU32 (inbuf+8);
  x4 = GETU32 (inbuf+12);

  OP (x1, x2, x3, x4, 0);
  OP (x3, x4, x1, x2, 2);
  OP (x1, x2, x3, x4, 4);
  OP (x3, x4, x1, x2, 6);
  OP (x1, x2, x3, x4, 8);
  OP (x3, x4, x1, x2, 10);
  OP (x1, x2, x3, x4, 12);
  OP (x3, x4, x1, x2, 14);
  OP (x1, x2, x3, x4, 16);
  OP (x3, x4, x1, x2, 18);
  OP (x1, x2, x3, x4, 20);
  OP (x3, x4, x1, x2, 22);
  OP (x1, x2, x3, x4, 24);
  OP (x3, x4, x1, x2, 26);
  OP (x1, x2, x3, x4, 28);
  OP (x3, x4, x1, x2, 30);

  PUTU32 (outbuf, x3);
  PUTU32 (outbuf+4, x4);
  PUTU32 (outbuf+8, x1);
  PUTU32 (outbuf+12, x2);
}