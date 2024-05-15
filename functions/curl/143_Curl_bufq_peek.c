bool Curl_bufq_peek(struct bufq *q,
                    const unsigned char **pbuf, size_t *plen)
{
  if(q->head && chunk_is_empty(q->head)) {
    prune_head(q);
  }
  if(q->head && !chunk_is_empty(q->head)) {
    chunk_peek(q->head, pbuf, plen);
    return TRUE;
  }
  *pbuf = NULL;
  *plen = 0;
  return FALSE;
}