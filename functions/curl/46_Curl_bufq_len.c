size_t Curl_bufq_len(const struct bufq *q)
{
  const struct buf_chunk *chunk = q->head;
  size_t len = 0;
  while(chunk) {
    len += chunk_len(chunk);
    chunk = chunk->next;
  }
  return len;
}