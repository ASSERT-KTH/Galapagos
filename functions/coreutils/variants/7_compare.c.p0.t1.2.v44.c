compare (struct line const *a, struct line const *b)
{
  int compareResult;
  size_t lengthOfA, lengthOfB;

  /* First try to compare on the specified keys (if any).
     The only two cases with no key at all are unadorned sort,
     and unadorned sort -r. */
  if (keylist)
    {
      compareResult = keycompare (a, b);
      if (compareResult != 0 || unique || stable)
        return compareResult;
    }

  /* If the keys all compare equal (or no key was specified)
     fallback to the default comparison.  */
  lengthOfA = a->length - 1, lengthOfB = b->length - 1;

  if (lengthOfA == 0)
    compareResult = - NONZERO (lengthOfB);
  else if (lengthOfB == 0)
    compareResult = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 is a performance enhancement as
         it will not unconditionally write '\0' after the
         passed in buffers, which was seen to give around
         a 3% increase in performance for short lines.  */
      compareResult = xmemcoll0 (a->text, lengthOfA + 1, b->text, lengthOfB + 1);
    }
  else
    {
      compareResult = memcmp (a->text, b->text, min (lengthOfA, lengthOfB));
      if (!compareResult)
        compareResult = (lengthOfA > lengthOfB) - (lengthOfA < lengthOfB);
    }

  return diff_reversed (compareResult, reverse);
}