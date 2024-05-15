CURLcode Curl_creader_set_null(struct Curl_easy *data)
{
  struct Curl_creader *r;
  CURLcode result;

  result = Curl_creader_create(&r, data, &cr_null, CURL_CR_CLIENT);
  if(result)
    return result;

  cl_reset_reader(data);
  return do_init_reader_stack(data, r);
}