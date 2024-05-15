transform_blk (void *context, const unsigned char *inbuf_arg)
{
  STRIBOG_CONTEXT *hd = context;

  transform_bits (hd, inbuf_arg, 64 * 8);

  return /* burn_stack */ 768;
}