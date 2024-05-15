static CURLcode cf_progress_egress(struct Curl_cfilter *cf,
                                   struct Curl_easy *data)
{
  struct cf_osslq_ctx *ctx = cf->ctx;
  CURLcode result = CURLE_OK;

  if(!ctx->tls.ossl.ssl)
    goto out;

  ERR_clear_error();
  result = h3_send_streams(cf, data);
  if(result)
    goto out;

  if(!SSL_handle_events(ctx->tls.ossl.ssl)) {
    int detail = SSL_get_error(ctx->tls.ossl.ssl, 0);
    result = cf_osslq_ssl_err(cf, data, detail, CURLE_SEND_ERROR);
  }

  result = cf_osslq_check_and_unblock(cf, data);

out:
  CURL_TRC_CF(data, cf, "progress_egress -> %d", result);
  return result;
}