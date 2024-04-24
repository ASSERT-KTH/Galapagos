ldb_now_usec(void) {
  uint64_t ticks;
  FILETIME ft;

  GetSystemTimeAsFileTime(&ft);

  ticks = ((uint64_t)ft.dwHighDateTime << 32) | ft.dwLowDateTime;

  return ticks / 10;
}