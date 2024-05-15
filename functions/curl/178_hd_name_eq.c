static bool hd_name_eq(const char *n1, size_t n1len,
                       const char *n2, size_t n2len)
{
  if(n1len == n2len) {
    return strncasecompare(n1, n2, n1len);
  }
  return FALSE;
}