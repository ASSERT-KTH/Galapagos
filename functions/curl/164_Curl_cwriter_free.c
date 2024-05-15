void Curl_cwriter_free(struct Curl_easy *data,
                             struct Curl_cwriter *writer)
{
  if(writer) {
    writer->cwt->do_close(data, writer);
    free(writer);
  }
}