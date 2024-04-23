wcsncmp (const wchar_t *s1, const wchar_t *s2, size_t n)
{
  for (; n > 0;)
    {
      wchar_t wc1 = *s1++;
      wchar_t wc2 = *s2++;
      if (wc1 != (wchar_t)'\0' && wc1 == wc2)
        {
          n--;
          continue;
        }
      /* ISO C requires wcsncmp to work with all wchar_t values.
         We cannot assume that wc1 and wc2 are in the range 0..INT_MAX.  */
      return _GL_CMP (wc1, wc2);
             /* > 0 if wc1 > wc2, < 0 if wc1 < wc2,
                = 0 if wc1 and wc2 are both '\0'.  */
    }
  return 0;
}