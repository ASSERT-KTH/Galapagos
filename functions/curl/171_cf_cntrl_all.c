static CURLcode cf_cntrl_all(struct connectdata *conn,
                             struct Curl_easy *data,
                             bool ignore_result,
                             int event, int arg1, void *arg2)
{
  CURLcode result = CURLE_OK;
  size_t i;

  for(i = 0; i < ARRAYSIZE(conn->cfilter); ++i) {
    result = Curl_conn_cf_cntrl(conn->cfilter[i], data, ignore_result,
                                event, arg1, arg2);
    if(!ignore_result && result)
      break;
  }
  return result;
}