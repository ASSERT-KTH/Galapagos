char *OPENSSL_strdup(const char *s) {
  if (s == NULL) {
    return NULL;
  }
  const size_t len = strlen(s) + 1;
  char *ret = OPENSSL_malloc(len);
  if (ret == NULL) {
    return NULL;
  }
  OPENSSL_memcpy(ret, s, len);
  return ret;
}