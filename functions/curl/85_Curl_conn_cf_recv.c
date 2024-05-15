ssize_t Curl_conn_cf_recv(struct Curl_cfilter *cf, struct Curl_easy *data,
                          char *buf, size_t len, CURLcode *err)
{
  if(cf)
    return cf->cft->do_recv(cf, data, buf, len, err);
  *err = CURLE_RECV_ERROR;
  return -1;
}