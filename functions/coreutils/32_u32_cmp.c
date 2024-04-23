u32_cmp (const uint32_t *s1, const uint32_t *s2, size_t n)
{
  for (; n > 0;)
    {
      uint32_t uc1 = *s1++;
      uint32_t uc2 = *s2++;
      if (uc1 == uc2)
        {
          n--;
          continue;
        }
      /* Note that uc1 and uc2 each have at most 31 bits. */
      return (int)uc1 - (int)uc2;
      /* > 0 if uc1 > uc2, < 0 if uc1 < uc2. */
    }
  return 0;
}