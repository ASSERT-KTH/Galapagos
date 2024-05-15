static void drain_stream(struct Curl_cfilter *cf,
                         struct Curl_easy *data,
                         struct h2_stream_ctx *stream)
{
  unsigned char bits;

  (void)cf;
  bits = CURL_CSELECT_IN;
  if(!stream->send_closed &&
     (stream->upload_left || stream->upload_blocked_len))
    bits |= CURL_CSELECT_OUT;
  if(data->state.select_bits != bits) {
    CURL_TRC_CF(data, cf, "[%d] DRAIN select_bits=%x",
                stream->id, bits);
    data->state.select_bits = bits;
    Curl_expire(data, 0, EXPIRE_RUN_NOW);
  }
}