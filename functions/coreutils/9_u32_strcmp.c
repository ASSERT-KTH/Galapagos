u32_strcmp (const uint32_t *s1, const uint32_t *s2)
{
  for (;;)
    {
      uint32_t uc1 = *s1++;
      uint32_t uc2 = *s2++;
      if (uc1 != 0 && uc1 == uc2)
        continue;
      /* Note that uc1 and uc2 each have at most 31 bits. */
      return (int)uc1 - (int)uc2;
      /* > 0 if uc1 > uc2, < 0 if uc1 < uc2. */
    }
}