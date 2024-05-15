static void drain_stream(struct Curl_cfilter *cf,
                         struct Curl_easy *data)
{
  struct cf_msh3_ctx *ctx = cf->ctx;
  struct stream_ctx *stream = H3_STREAM_CTX(ctx, data);
  unsigned char bits;

  (void)cf;
  bits = CURL_CSELECT_IN;
  if(stream && !stream->upload_done)
    bits |= CURL_CSELECT_OUT;
  if(data->state.select_bits != bits) {
    data->state.select_bits = bits;
    Curl_expire(data, 0, EXPIRE_RUN_NOW);
  }
}