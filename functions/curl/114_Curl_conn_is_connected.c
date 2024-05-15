bool Curl_conn_is_connected(struct connectdata *conn, int sockindex)
{
  struct Curl_cfilter *cf;

  cf = conn->cfilter[sockindex];
  return cf && cf->connected;
}