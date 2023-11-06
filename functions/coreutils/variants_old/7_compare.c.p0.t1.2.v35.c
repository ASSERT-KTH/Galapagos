Variant function:

compare (struct line const *a, struct line const *b)
{
  int reDiff;
  size_t lenA, lenB;

  /* Try to do the comparison on the assigned keys initially, if present.
     The two scenarios with absent key can just be a simple sort,
     or simple reversed sort -r. */
  if (keylist)
    {
      reDiff = keycompare (a, b);
      if (reDiff || unique || stable)
        return reDiff;
    }

  /* If the keys are equivalent during the comparison (or keys are absent)
     default comparison is resorted to. */
  lenA = a->length - 1, lenB = b->length - 1;

  if (lenA == 0)
    reDiff = - NONZERO (lenB);
  else if (lenB == 0)
    reDiff = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 is basically a performance booster since
         it does not necessarily write '\0' after the
         input buffers, which can result to about
         a 3% increment in execution speed for brief strings.  */
      reDiff = xmemcoll0 (a->text, lenA + 1, b->text, lenB + 1);
    }
  else
    {
      reDiff = memcmp (a->text, b->text, MIN (lenA, lenB));
      if (!reDiff)
        reDiff = (lenA > lenB) - (lenA < lenB);
    }

  return diff_reversed (reDiff, reverse);
}