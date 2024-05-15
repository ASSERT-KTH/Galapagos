CURLcode Curl_cwriter_write(struct Curl_easy *data,
                             struct Curl_cwriter *writer, int type,
                             const char *buf, size_t nbytes)
{
  if(!writer)
    return CURLE_WRITE_ERROR;
  return writer->cwt->do_write(data, writer, type, buf, nbytes);
}