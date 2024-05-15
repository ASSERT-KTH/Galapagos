Curl_ssl_cf_get_primary_config(struct Curl_cfilter *cf)
{
#ifdef CURL_DISABLE_PROXY
  return &cf->conn->ssl_config;
#else
  return Curl_ssl_cf_is_proxy(cf)?
    &cf->conn->proxy_ssl_config : &cf->conn->ssl_config;
#endif
}