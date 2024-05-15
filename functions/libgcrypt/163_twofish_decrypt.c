twofish_decrypt (void *context, byte *out, const byte *in)
{
  TWOFISH_context *ctx = context;

  do_twofish_decrypt (ctx, out, in);
  return /*burn_stack*/ (24+3*sizeof (void*));
}