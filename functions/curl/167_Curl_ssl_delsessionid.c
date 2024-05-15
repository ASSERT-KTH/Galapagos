void Curl_ssl_delsessionid(struct Curl_easy *data, void *ssl_sessionid)
{
  size_t i;

  for(i = 0; i < data->set.general_ssl.max_ssl_sessions; i++) {
    struct Curl_ssl_session *check = &data->state.session[i];

    if(check->sessionid == ssl_sessionid) {
      Curl_ssl_kill_session(check);
      break;
    }
  }
}