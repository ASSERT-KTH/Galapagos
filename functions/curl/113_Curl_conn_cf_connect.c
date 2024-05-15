CURLcode Curl_conn_cf_connect(struct Curl_cfilter *cf,
                              struct Curl_easy *data,
                              bool blocking, bool *done)
{
  if(cf)
    return cf->cft->do_connect(cf, data, blocking, done);
  return CURLE_FAILED_INIT;
}