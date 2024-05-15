CURLcode Curl_bufq_cwrite(struct bufq *q,
                          const char *buf, size_t len,
                          size_t *pnwritten)
{
  ssize_t n;
  CURLcode result;
  n = Curl_bufq_write(q, (const unsigned char *)buf, len, &result);
  *pnwritten = (n < 0)? 0 : (size_t)n;
  return result;
}