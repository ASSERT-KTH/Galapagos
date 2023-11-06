compare (struct line const *a, struct line const *b)
{
  int result;
  size_t lenOfA, lenOfB;

  /* Compare using the specified keys (if any). 
     The only two cases with no key at all are a regular sort, or a reverse sort without additional conditions. */
  if (keylist)
    {
      result = keycompare (a, b);
      if (result || unique || stable)
        return result;
    }

  /* If keys are all similar or were not introduced at all, we fall back on the usual comparison based on length. */
  lenOfA = a->length - 1;
  lenOfB = b->length - 1;

  if (lenOfA == 0)
    result = - NONZERO (lenOfB);
  else if (lenOfB == 0)
    result = 1;
  else if (hard_LC_COLLATE)
    {
      /* 'xmemcoll0' is used for performance increase since
      it doesn't compulsarily add '\0' after the input buffers,
      thus giving approximately 3% improvement for short lines. */
      result = xmemcoll0 (a->text, lenOfA + 1, b->text, lenOfB + 1);
    }
  else
    {
      result = memcmp(a->text, b->text, MIN (lenOfA, lenOfB));
      if (!result)
        result = (lenOfA > lenOfB) - (lenOfA < lenOfB);
    }
    
  return diff_reversed (result, reverse);
}