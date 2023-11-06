compare (struct line const *a, struct line const *b)
{
  int diff_result;
  size_t alength, blength;

  /* Comparing with keylist if its available. 
     If no key is provided, perform the raw sort. */
  if (keylist)
    {
      diff_result = keycompare (a, b);
      if (diff_result != 0 || unique || stable)
        return diff_result;
    }

  /* If no keys are provided or keys are equal,
     follow the default sorting. */
  alength = a->length - 1, blength = b->length - 1;

  if (alength == 0)
    diff_result = - NONZERO (blength);
  else if (blength == 0)
    diff_result = NONZERO (alength);
  else if (hard_LC_COLLATE)
    {
      /* Optimisation is done when performing xmemcoll0 
         as it will not place '\0' after the input buffers.
         This increases around a 3% in performance for small 
         lines.  */
      diff_result = xmemcoll0 (a->text, alength + 1, b->text, blength + 1);
    }
  else
    {
      diff_result = memcmp (a->text, b->text, MIN (alength, blength));
      if (!diff_result)
        diff_result = (alength > blength) - (alength < blength);
    }

  return diff_reversed (diff_result, reverse);
}