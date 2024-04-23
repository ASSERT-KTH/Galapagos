wcscmp (const wchar_t *s1, const wchar_t *s2)
{
  for (;;)
    {
      wchar_t wc1 = *s1++;
      wchar_t wc2 = *s2++;
      if (wc1 != (wchar_t)'\0' && wc1 == wc2)
        continue;
      /* ISO C requires wcscmp to work with all wchar_t values.
         We cannot assume that wc1 and wc2 are in the range 0..INT_MAX.  */
      return _GL_CMP (wc1, wc2);
             /* > 0 if wc1 > wc2, < 0 if wc1 < wc2,
                = 0 if wc1 and wc2 are both '\0'.  */
    }
}