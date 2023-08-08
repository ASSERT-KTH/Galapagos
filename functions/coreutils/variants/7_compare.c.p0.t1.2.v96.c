compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* Two types of unadorned sorts have no key specification.
     Implement key comparison first concern (if keys are provided). */
  if (keylist)
    {
      diff = keycompare (a, b);
      /* If lines are unique or order needs to be strictly followed 
         just return the difference */
      if (diff || unique || stable)
        return diff;
    }

  /* If a & b lines are equal (or no keys defined) execute default comparison. */
  alen = a->length - 1, blen = b->length - 1;

  /* If any line has length of zero, treat the other as larger. */
  if (alen == 0)
    diff = blen ? -1 : 0;
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* Applying xmemcoll0 helps improve performance by refraining 
         from obligatorily appending '\0' to buffers which results 
         in around 3% increment in performance for short strings. */
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      /* If line sizes differ, use memcmp comparison upto minimum of 
         provided lengths. If they equal, calculate diff using expression 
         evaluating to 1, -1 or 0 for alen to be more, less or equal to blen resp. */
      diff = memcmp (a->text, b->text, (alen < blen) ? alen : blen);
      if (!diff)
        diff = (alen > blen) ? 1 : (alen < blen) ? -1 : 0;
    }

  /* If comparison needed in reversed order, call logical function for 
     reversing result.*/
  return diff_reversed (diff, reverse);
}