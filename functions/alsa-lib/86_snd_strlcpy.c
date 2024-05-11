size_t snd_strlcpy(char *dst, const char *src, size_t size)
{
  size_t ret = strlen(src);
  if (size) {
    size_t len = ret >= size ? size - 1 : ret;
    memcpy(dst, src, len);
    dst[len] = '\0';
  }
  return ret;
}