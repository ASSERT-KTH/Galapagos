ldb_open(const char *name, int flags, uint32_t mode) {
  int fd;

  do {
    fd = ldb_try_open(name, flags, mode);
  } while (fd < 0 && errno == EINTR);

  return fd;
}