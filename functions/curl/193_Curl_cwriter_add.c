CURLcode Curl_cwriter_add(struct Curl_easy *data,
                          struct Curl_cwriter *writer)
{
  CURLcode result;
  struct Curl_cwriter **anchor = &data->req.writer_stack;

  if(!*anchor) {
    result = do_init_writer_stack(data);
    if(result)
      return result;
  }

  /* Insert the writer as first in its phase.
   * Skip existing writers of lower phases. */
  while(*anchor && (*anchor)->phase < writer->phase)
    anchor = &((*anchor)->next);
  writer->next = *anchor;
  *anchor = writer;
  return CURLE_OK;
}