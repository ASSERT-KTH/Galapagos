CURLcode Curl_conn_connect(struct Curl_easy *data,
                           int sockindex,
                           bool blocking,
                           bool *done)
{
  struct Curl_cfilter *cf;
  CURLcode result = CURLE_OK;

  DEBUGASSERT(data);
  DEBUGASSERT(data->conn);

  cf = data->conn->cfilter[sockindex];
  DEBUGASSERT(cf);
  if(!cf)
    return CURLE_FAILED_INIT;

  *done = cf->connected;
  if(!*done) {
    result = cf->cft->do_connect(cf, data, blocking, done);
    if(!result && *done) {
      Curl_conn_ev_update_info(data, data->conn);
      conn_report_connect_stats(data, data->conn);
      data->conn->keepalive = Curl_now();
    }
    else if(result) {
      conn_report_connect_stats(data, data->conn);
    }
  }

  return result;
}