CURLcode curl_mime_data_cb(curl_mimepart *part,
                           curl_off_t datasize,
                           curl_read_callback readfunc,
                           curl_seek_callback seekfunc,
                           curl_free_callback freefunc,
                           void *arg)
{
  (void) part;
  (void) datasize;
  (void) readfunc;
  (void) seekfunc;
  (void) freefunc;
  (void) arg;
  return CURLE_NOT_BUILT_IN;
}