CURLcode Curl_cf_socket_peek(struct Curl_cfilter *cf,
                             struct Curl_easy *data,
                             curl_socket_t *psock,
                             const struct Curl_sockaddr_ex **paddr,
                             struct ip_quadruple *pip)
{
  (void)data;
  if(cf_is_socket(cf) && cf->ctx) {
    struct cf_socket_ctx *ctx = cf->ctx;

    if(psock)
      *psock = ctx->sock;
    if(paddr)
      *paddr = &ctx->addr;
    if(pip)
      *pip = ctx->ip;
    return CURLE_OK;
  }
  return CURLE_FAILED_INIT;
}