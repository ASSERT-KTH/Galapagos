CURLMcode curl_multi_poll(struct Curl_multi *multi,
                          struct curl_waitfd extra_fds[],
                          unsigned int extra_nfds,
                          int timeout_ms,
                          int *ret)
{
  return multi_wait(multi, extra_fds, extra_nfds, timeout_ms, ret, TRUE,
                    TRUE);
}