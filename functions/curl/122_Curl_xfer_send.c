CURLcode Curl_xfer_send(struct Curl_easy *data,
                        const void *buf, size_t blen,
                        size_t *pnwritten)
{
  CURLcode result;
  int sockindex;

  if(!data || !data->conn)
    return CURLE_FAILED_INIT;
  /* FIXME: would like to enable this, but some protocols (MQTT) do not
   * setup the transfer correctly, it seems
  if(data->conn->writesockfd == CURL_SOCKET_BAD) {
    failf(data, "transfer not setup for sending");
    DEBUGASSERT(0);
    return CURLE_SEND_ERROR;
  } */
  sockindex = ((data->conn->writesockfd != CURL_SOCKET_BAD) &&
               (data->conn->writesockfd == data->conn->sock[SECONDARYSOCKET]));
  result = Curl_conn_send(data, sockindex, buf, blen, pnwritten);
  if(result == CURLE_AGAIN) {
    result = CURLE_OK;
    *pnwritten = 0;
  }
  else if(!result && *pnwritten)
    data->info.request_size += *pnwritten;

  return result;
}