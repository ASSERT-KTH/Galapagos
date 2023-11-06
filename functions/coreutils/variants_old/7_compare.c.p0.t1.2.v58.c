compare (struct line const *a, struct line const *b)
{
  int difference;
  size_t lengthA, lengthB;

  /* First try to compare on the specific keys (if any).
     Only two cases with no key are unmodified sort,
     and unmodified sort -r. */
  if (keylist)
    {
      difference = keycompare (a, b);
      if (difference || unique || stable)
        return difference;
    }

  /* Fall to the default comparison if no difference is found in keys (or keys were not provided) */
  lengthA = a->length - 1, lengthB = b->length - 1;

  if (lengthA == 0)
    difference = - NONZERO (lengthB);
  else if (lengthB == 0)
    difference = 1;
  else if (hard_LC_COLLATE)
    {
      /* Using xmemcoll0 to improve performance by avoiding unconditioned '\0' writing at the end of
         passed in buffers. It's observed delivering approximately 3% increase in performance for short lines. */
      difference = xmemcoll0 (a->text, lengthA + 1, b->text, lengthB + 1);
    }
  else
    {
      difference = memcmp (a->text, b->text, MIN (lengthA, lengthB));
      if (!difference)
        difference = (lengthA > lengthB) - (lengthA < lengthB);
    }

  return diff_reversed (difference, reverse);
}