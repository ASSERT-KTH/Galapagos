bool Curl_bufq_is_full(const struct bufq *q)
{
  if(!q->tail || q->spare)
    return FALSE;
  if(q->chunk_count < q->max_chunks)
    return FALSE;
  if(q->chunk_count > q->max_chunks)
    return TRUE;
  /* we have no spares and cannot make more, is the tail full? */
  return chunk_is_full(q->tail);
}