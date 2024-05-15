static void sigpipe_ignore(struct Curl_easy *data,
                           struct sigpipe_ignore *ig)
{
  /* get a local copy of no_signal because the Curl_easy might not be
     around when we restore */
  ig->no_signal = data->set.no_signal;
  if(!data->set.no_signal) {
    struct sigaction action;
    /* first, extract the existing situation */
    sigaction(SIGPIPE, NULL, &ig->old_pipe_act);
    action = ig->old_pipe_act;
    /* ignore this signal */
    action.sa_handler = SIG_IGN;
    sigaction(SIGPIPE, &action, NULL);
  }
}