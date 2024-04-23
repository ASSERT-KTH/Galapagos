btc_time_msec(void) {
#ifdef BTC_HAVE_CLOCK
  struct timespec ts;

  btc_clock_gettime(CLOCK_MONOTONIC, &ts);

  return ((uint64_t)ts.tv_sec * 1000) + (ts.tv_nsec / 1000000);
#else
  struct timeval tv;

  btc_gettimeofday(&tv);

  return ((uint64_t)tv.tv_sec * 1000) + (tv.tv_usec / 1000);
#endif
}