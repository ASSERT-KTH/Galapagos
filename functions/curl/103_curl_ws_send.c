CURL_EXTERN CURLcode curl_ws_send(CURL *curl, const void *buffer,
                                  size_t buflen, size_t *sent,
                                  curl_off_t fragsize,
                                  unsigned int flags)
{
  (void)curl;
  (void)buffer;
  (void)buflen;
  (void)sent;
  (void)fragsize;
  (void)flags;
  return CURLE_NOT_BUILT_IN;
}