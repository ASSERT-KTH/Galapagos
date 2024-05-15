ssize_t Curl_bufq_read(struct bufq *q, unsigned char *buf, size_t len,
                       CURLcode *err)
{
  ssize_t nread = 0;
  size_t n;

  *err = CURLE_OK;
  while(len && q->head) {
    n = chunk_read(q->head, buf, len);
    if(n) {
      nread += n;
      buf += n;
      len -= n;
    }
    prune_head(q);
  }
  if(nread == 0) {
    *err = CURLE_AGAIN;
    return -1;
  }
  return nread;
}