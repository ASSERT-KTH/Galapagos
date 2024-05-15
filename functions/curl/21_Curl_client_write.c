CURLcode Curl_client_write(struct Curl_easy *data,
                           int type, const char *buf, size_t blen)
{
  CURLcode result;

  /* it is one of those, at least */
  DEBUGASSERT(type & (CLIENTWRITE_BODY|CLIENTWRITE_HEADER|CLIENTWRITE_INFO));
  /* BODY is only BODY (with optional EOS) */
  DEBUGASSERT(!(type & CLIENTWRITE_BODY) ||
              ((type & ~(CLIENTWRITE_BODY|CLIENTWRITE_EOS)) == 0));
  /* INFO is only INFO (with optional EOS) */
  DEBUGASSERT(!(type & CLIENTWRITE_INFO) ||
              ((type & ~(CLIENTWRITE_INFO|CLIENTWRITE_EOS)) == 0));

  if(!data->req.writer_stack) {
    result = do_init_writer_stack(data);
    if(result)
      return result;
    DEBUGASSERT(data->req.writer_stack);
  }

  result = Curl_cwriter_write(data, data->req.writer_stack, type, buf, blen);
  CURL_TRC_WRITE(data, "client_write(type=%x, len=%zu) -> %d",
                 type, blen, result);
  return result;
}