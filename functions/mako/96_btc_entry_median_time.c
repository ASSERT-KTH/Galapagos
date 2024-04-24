btc_entry_median_time(const btc_entry_t *entry) {
  int64_t tvec[BTC_MEDIAN_TIMESPAN];
  int len = 0;
  int i;

  for (i = 0; i < BTC_MEDIAN_TIMESPAN && entry != NULL; i++) {
    tvec[len++] = entry->header.time;
    entry = entry->prev;
  }

  qsort(tvec, len, sizeof(int64_t), cmptime);

  return tvec[len >> 1];
}