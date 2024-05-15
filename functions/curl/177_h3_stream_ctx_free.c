static void h3_stream_ctx_free(struct h3_stream_ctx *stream)
{
  cf_osslq_stream_cleanup(&stream->s);
  Curl_bufq_free(&stream->sendbuf);
  Curl_bufq_free(&stream->recvbuf);
  Curl_h1_req_parse_free(&stream->h1);
  free(stream);
}