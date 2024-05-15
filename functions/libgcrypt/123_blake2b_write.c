static void blake2b_write(void *ctx, const void *inbuf, size_t inlen)
{
  BLAKE2B_CONTEXT *c = ctx;
  BLAKE2B_STATE *S = &c->state;
  blake2_write(S, inbuf, inlen, c->buf, &c->buflen, BLAKE2B_BLOCKBYTES,
	       blake2b_transform);
}