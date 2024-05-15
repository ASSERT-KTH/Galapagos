Hash_prefix (unsigned char *out, int b, const unsigned char *in, int inlen)
{
  unsigned char x[inlen + 1];
  unsigned char h[64];
  int i;

  x[0] = b;
  for (i = 0; i < inlen; ++i)
    x[i + 1] = in[i];
  crypto_hash_sha512 (h, x, inlen + 1);
  for (i = 0; i < 32; ++i)
    out[i] = h[i];
}