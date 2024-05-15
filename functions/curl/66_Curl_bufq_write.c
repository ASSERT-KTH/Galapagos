ssize_t Curl_bufq_write(struct bufq *q,
                        const unsigned char *buf, size_t len,
                        CURLcode *err)
{
  struct buf_chunk *tail;
  ssize_t nwritten = 0;
  size_t n;

  DEBUGASSERT(q->max_chunks > 0);
  while(len) {
    tail = get_non_full_tail(q);
    if(!tail) {
      if((q->chunk_count < q->max_chunks) || (q->opts & BUFQ_OPT_SOFT_LIMIT)) {
        *err = CURLE_OUT_OF_MEMORY;
        return -1;
      }
      break;
    }
    n = chunk_append(tail, buf, len);
    if(!n)
      break;
    nwritten += n;
    buf += n;
    len -= n;
  }
  if(nwritten == 0 && len) {
    *err = CURLE_AGAIN;
    return -1;
  }
  *err = CURLE_OK;
  return nwritten;
}