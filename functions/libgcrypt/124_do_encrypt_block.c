do_encrypt_block ( BLOWFISH_context *bc, byte *outbuf, const byte *inbuf )
{
  u32 d1, d2;

  d1 = buf_get_be32(inbuf);
  d2 = buf_get_be32(inbuf + 4);
  do_encrypt( bc, &d1, &d2 );
  buf_put_be32(outbuf, d1);
  buf_put_be32(outbuf + 4, d2);
}