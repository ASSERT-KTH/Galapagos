void Curl_bufq_skip(struct bufq *q, size_t amount)
{
  size_t n;

  while(amount && q->head) {
    n = chunk_skip(q->head, amount);
    amount -= n;
    prune_head(q);
  }
}