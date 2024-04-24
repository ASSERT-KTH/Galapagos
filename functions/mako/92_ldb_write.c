ldb_write(int fd, const void *src, size_t len) {
  const unsigned char *buf = src;
  int64_t cnt = 0;

  while (len > 0) {
    size_t max = LDB_MIN(len, 1 << 30);
    int nwrite;

    do {
      nwrite = write(fd, buf, max);
    } while (nwrite < 0 && errno == EINTR);

    if (nwrite < 0)
      return -1;

    buf += nwrite;
    len -= nwrite;
    cnt += nwrite;
  }

  return cnt;
}