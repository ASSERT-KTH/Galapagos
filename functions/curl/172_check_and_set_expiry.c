static CURLcode check_and_set_expiry(struct Curl_cfilter *cf,
                                     struct Curl_easy *data)
{
  struct cf_osslq_ctx *ctx = cf->ctx;
  CURLcode result = CURLE_OK;
  struct timeval tv;
  timediff_t timeoutms;
  int is_infinite = TRUE;

  if(ctx->tls.ossl.ssl &&
    SSL_get_event_timeout(ctx->tls.ossl.ssl, &tv, &is_infinite) &&
    !is_infinite) {
    timeoutms = curlx_tvtoms(&tv);
    /* QUIC want to be called again latest at the returned timeout */
    if(timeoutms <= 0) {
      result = cf_progress_ingress(cf, data);
      if(result)
        goto out;
      result = cf_progress_egress(cf, data);
      if(result)
        goto out;
      if(SSL_get_event_timeout(ctx->tls.ossl.ssl, &tv, &is_infinite)) {
        timeoutms = curlx_tvtoms(&tv);
      }
    }
    if(!is_infinite) {
      Curl_expire(data, timeoutms, EXPIRE_QUIC);
      CURL_TRC_CF(data, cf, "QUIC expiry in %ldms", (long)timeoutms);
    }
  }
out:
  return result;
}