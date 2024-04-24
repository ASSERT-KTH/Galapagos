ldb_join(char *zp, size_t zn, const char *xp, const char *yp) {
  size_t xn = strlen(xp);
  size_t yn = strlen(yp);

  if (xn + yn + 2 > zn)
    return 0;

  if (zp != xp) {
    while (*xp)
      *zp++ = *xp++;
  } else {
    zp += xn;
  }

#if defined(_WIN32)
  *zp++ = '\\';
#else
  *zp++ = '/';
#endif

  while (*yp)
    *zp++ = *yp++;

  *zp = '\0';

  return 1;
}