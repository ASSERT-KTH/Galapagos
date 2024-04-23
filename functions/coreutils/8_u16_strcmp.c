u16_strcmp (const uint16_t *s1, const uint16_t *s2)
{
  /* Note that the UTF-16 encoding does NOT preserve lexicographic order.
     Namely, if uc1 is a 16-bit character and [uc2a,uc2b] is a surrogate pair,
     we must enforce uc1 < [uc2a,uc2b], even if uc1 > uc2a.  */
  for (;;)
    {
      uint16_t c1 = *s1++;
      uint16_t c2 = *s2++;
      if (c1 != 0 && c1 == c2)
        continue;
      if (c1 < 0xd800 || c1 >= 0xe000)
        {
          if (!(c2 < 0xd800 || c2 >= 0xe000))
            /* c2 is a surrogate, but c1 is not.  */
            return -1;
        }
      else
        {
          if (c2 < 0xd800 || c2 >= 0xe000)
            /* c1 is a surrogate, but c2 is not.  */
            return 1;
        }
      return (int)c1 - (int)c2;
      /* > 0 if c1 > c2, < 0 if c1 < c2. */
    }
}