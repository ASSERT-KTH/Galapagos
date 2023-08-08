compare (struct line const *a, struct line const *b)
{
  int diff_result;
  size_t lengthA, lengthB;

  /* Start by comparing on the specified keys (if any).
     The only cases without a key are plain sort and plain sort -r */
  if (keylist)
    {
      diff_result = keycompare (a, b);
  if (diff_result || unique || stable)
        return diff_result;
    }

  /* Default comparison when keys are either equal or not specified */
  lengthA = a->length - 1, lengthB = b->length - 1;

  if (lengthA == 0)
    diff_result = - NONZERO (lengthB);
  else if (lengthB == 0)
    diff_result = 1;
  else if (hard_LC_COLLATE)
    {
      /* Optimization with xmemcoll0 as it will not unconditionally
         put '\0' after the passed in buffers, which leads to approximately 3%
         increase in performance for shorter lines */
      diff_result = xmemcoll0 (a->text, lengthA + 1, b->text, lengthB + 1);
    }
  else
    {
      diff_result = memcmp (a->text, b->text, MIN (lengthA, lengthB));
      if (!diff_result)
        diff_result = (lengthA > lengthB) - (lengthA < lengthB);
    }

  return diff_reversed (diff_result, reverse);
}