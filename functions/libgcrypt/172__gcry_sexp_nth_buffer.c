_gcry_sexp_nth_buffer (const gcry_sexp_t list, int number, size_t *rlength)
{
  const char *s;
  size_t n;
  char *buf;

  *rlength = 0;
  s = do_sexp_nth_data (list, number, &n);
  if (!s || !n)
    return NULL;
  buf = xtrymalloc (n);
  if (!buf)
    return NULL;
  memcpy (buf, s, n);
  *rlength = n;
  return buf;
}