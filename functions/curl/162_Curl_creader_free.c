void Curl_creader_free(struct Curl_easy *data, struct Curl_creader *reader)
{
  if(reader) {
    reader->crt->do_close(data, reader);
    free(reader);
  }
}