static CURLcode imap_sendf(struct Curl_easy *data, const char *fmt, ...)
{
  CURLcode result = CURLE_OK;
  struct imap_conn *imapc = &data->conn->proto.imapc;

  DEBUGASSERT(fmt);

  /* Calculate the tag based on the connection ID and command ID */
  msnprintf(imapc->resptag, sizeof(imapc->resptag), "%c%03d",
            'A' + curlx_sltosi((long)(data->conn->connection_id % 26)),
            ++imapc->cmdid);

  /* start with a blank buffer */
  Curl_dyn_reset(&imapc->dyn);

  /* append tag + space + fmt */
  result = Curl_dyn_addf(&imapc->dyn, "%s %s", imapc->resptag, fmt);
  if(!result) {
    va_list ap;
    va_start(ap, fmt);
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-nonliteral"
#endif
    result = Curl_pp_vsendf(data, &imapc->pp, Curl_dyn_ptr(&imapc->dyn), ap);
#ifdef __clang__
#pragma clang diagnostic pop
#endif
    va_end(ap);
  }
  return result;
}