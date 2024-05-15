ssize_t Curl_conn_cf_send(struct Curl_cfilter *cf, struct Curl_easy *data,
                          const void *buf, size_t len, CURLcode *err)
{
  if(cf)
    return cf->cft->do_send(cf, data, buf, len, err);
  *err = CURLE_SEND_ERROR;
  return -1;
}