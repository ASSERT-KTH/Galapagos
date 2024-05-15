Curl_ssl_cf_get_config(struct Curl_cfilter *cf, struct Curl_easy *data)
{
#ifdef CURL_DISABLE_PROXY
  (void)cf;
  return &data->set.ssl;
#else
  return Curl_ssl_cf_is_proxy(cf)? &data->set.proxy_ssl : &data->set.ssl;
#endif
}