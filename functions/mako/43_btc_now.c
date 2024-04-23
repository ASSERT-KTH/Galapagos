btc_now(void) {
  time_t now = time(NULL);

  CHECK(now != (time_t)-1);

  return (int64_t)now;
}