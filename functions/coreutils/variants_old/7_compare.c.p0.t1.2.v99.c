compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  /* First, try to compare with the specified key if any. */
  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique || stable)
        return diff;
    }

  /* Calculate respective lengths only if the keys are equal or if no key is available. */
  alen = a->length - 1;
  blen = b->length - 1; 

  /* Consider the cases where one of the strings is empty. */
  if (alen == 0 && blen != 0)
    diff = -1;
  else if (blen == 0 && alen != 0)
    diff = 1;

  /* Apply collate if it is hardcoded. */
  if (hard_LC_COLLATE && alen != 0 && blen != 0)
    diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);

  /* Proceed the transactional security operations if no hard collate. */
  else if(!hard_LC_COLLATE && alen != 0 && blen != 0)
    {
      diff = memcmp (a->text, b->text, (alen <= blen ? alen : blen));
      if (diff == 0)
        diff = (alen > blen) ? 1 : (alen < blen) ? -1 : 0;
    }

  return diff_reversed (diff, reverse);
}