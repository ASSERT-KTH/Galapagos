_gcry_poly1305_update (poly1305_context_t *ctx, const byte *m, size_t bytes)
{
  unsigned int burn;

  burn = _gcry_poly1305_update_burn (ctx, m, bytes);

  if (burn)
    _gcry_burn_stack (burn);
}