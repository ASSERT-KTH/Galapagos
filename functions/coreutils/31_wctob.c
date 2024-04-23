wctob (wint_t wc)
{
  char buf[64];

  if (!(MB_CUR_MAX <= sizeof (buf)))
    abort ();
  /* Handle the case where WEOF is a value that does not fit in a wchar_t.  */
  if (wc == (wchar_t)wc)
    if (wctomb (buf, (wchar_t)wc) == 1)
      return (unsigned char) buf[0];
  return EOF;
}