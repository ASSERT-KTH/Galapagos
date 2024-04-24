btc_retry_rdwr(int ret) {
  if (ret == -1) {
#ifdef EINTR
    if (errno == EINTR)
      return 1;
#endif
#ifdef EAGAIN
    if (errno == EAGAIN)
      return 1;
#endif
#ifdef EWOULDBLOCK
    if (errno == EWOULDBLOCK)
      return 1;
#endif
  }
  return 0;
}