ldb_write(HANDLE handle, const void *src, size_t len) {
  const unsigned char *buf = src;
  int64_t cnt = 0;

  while (len > 0) {
    DWORD max = LDB_MIN(len, 1 << 30);
    DWORD nwrite;

    if (!WriteFile(handle, buf, max, &nwrite, NULL))
      return -1;

    buf += nwrite;
    len -= nwrite;
    cnt += nwrite;
  }

  return cnt;
}