void curl_easy_cleanup(struct Curl_easy *data)
{
  if(GOOD_EASY_HANDLE(data)) {
    SIGPIPE_VARIABLE(pipe_st);
    sigpipe_ignore(data, &pipe_st);
    Curl_close(&data);
    sigpipe_restore(&pipe_st);
  }
}