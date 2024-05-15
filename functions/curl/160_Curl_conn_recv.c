CURLcode Curl_conn_recv(struct Curl_easy *data, int sockindex,
                        char *buf, size_t blen, ssize_t *n)
{
  CURLcode result = CURLE_OK;
  ssize_t nread;

  DEBUGASSERT(data->conn);
  nread = data->conn->recv[sockindex](data, sockindex, buf, blen, &result);
  DEBUGASSERT(nread >= 0 || result);
  DEBUGASSERT(nread < 0 || !result);
  *n = (nread >= 0)? (size_t)nread : 0;
  return result;
}