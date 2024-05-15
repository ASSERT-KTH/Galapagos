static CURLcode set_local_ip(struct Curl_cfilter *cf,
                             struct Curl_easy *data)
{
  struct cf_socket_ctx *ctx = cf->ctx;

#ifdef HAVE_GETSOCKNAME
  if((ctx->sock != CURL_SOCKET_BAD) &&
     !(data->conn->handler->protocol & CURLPROTO_TFTP)) {
    /* TFTP does not connect, so it cannot get the IP like this */

    char buffer[STRERROR_LEN];
    struct Curl_sockaddr_storage ssloc;
    curl_socklen_t slen = sizeof(struct Curl_sockaddr_storage);

    memset(&ssloc, 0, sizeof(ssloc));
    if(getsockname(ctx->sock, (struct sockaddr*) &ssloc, &slen)) {
      int error = SOCKERRNO;
      failf(data, "getsockname() failed with errno %d: %s",
            error, Curl_strerror(error, buffer, sizeof(buffer)));
      return CURLE_FAILED_INIT;
    }
    if(!Curl_addr2string((struct sockaddr*)&ssloc, slen,
                         ctx->ip.local_ip, &ctx->ip.local_port)) {
      failf(data, "ssloc inet_ntop() failed with errno %d: %s",
            errno, Curl_strerror(errno, buffer, sizeof(buffer)));
      return CURLE_FAILED_INIT;
    }
  }
#else
  (void)data;
  ctx->ip.local_ip[0] = 0;
  ctx->ip.local_port = -1;
#endif
  return CURLE_OK;
}