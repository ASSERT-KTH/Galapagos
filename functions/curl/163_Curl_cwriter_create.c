CURLcode Curl_cwriter_create(struct Curl_cwriter **pwriter,
                                   struct Curl_easy *data,
                                   const struct Curl_cwtype *cwt,
                                   Curl_cwriter_phase phase)
{
  struct Curl_cwriter *writer = NULL;
  CURLcode result = CURLE_OUT_OF_MEMORY;
  void *p;

  DEBUGASSERT(cwt->cwriter_size >= sizeof(struct Curl_cwriter));
  p = calloc(1, cwt->cwriter_size);
  if(!p)
    goto out;

  writer = (struct Curl_cwriter *)p;
  writer->cwt = cwt;
  writer->ctx = p;
  writer->phase = phase;
  result = cwt->do_init(data, writer);

out:
  *pwriter = result? NULL : writer;
  if(result)
    free(writer);
  return result;
}