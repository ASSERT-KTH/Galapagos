CURLcode Curl_xfer_recv(struct Curl_easy *data,
                        char *buf, size_t blen,
                        ssize_t *pnrcvd)
{
  int sockindex;

  if(!data || !data->conn)
    return CURLE_FAILED_INIT;
  /* FIXME: would like to enable this, but some protocols (MQTT) do not
   * setup the transfer correctly, it seems
  if(data->conn->sockfd == CURL_SOCKET_BAD) {
    failf(data, "transfer not setup for receiving");
    DEBUGASSERT(0);
    return CURLE_RECV_ERROR;
  } */
  sockindex = ((data->conn->sockfd != CURL_SOCKET_BAD) &&
               (data->conn->sockfd == data->conn->sock[SECONDARYSOCKET]));
  if(data->set.buffer_size > 0 && (size_t)data->set.buffer_size < blen)
    blen = (size_t)data->set.buffer_size;
  return Curl_conn_recv(data, sockindex, buf, blen, pnrcvd);
}