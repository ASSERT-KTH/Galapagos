static CURLcode ssl_push_certinfo_dyn(struct Curl_easy *data,
                                      int certnum,
                                      const char *label,
                                      struct dynbuf *ptr)
{
  size_t valuelen = Curl_dyn_len(ptr);
  char *value = Curl_dyn_ptr(ptr);

  CURLcode result = Curl_ssl_push_certinfo_len(data, certnum, label,
                                               value, valuelen);

  if(!certnum && !result)
    infof(data, "   %s: %s", label, value);

  return result;
}