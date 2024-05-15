_gcry_poly1305_finish (poly1305_context_t *ctx, byte mac[POLY1305_TAGLEN])
{
  unsigned int burn;

  burn = poly1305_final (ctx, mac);

  _gcry_burn_stack (burn);
}